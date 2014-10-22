package com.example.robotcolony;

import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

public class FreeLabyrinthScreen extends Activity implements OnItemClickListener{

	List<String> list;
	ListView listView;
	Button b_start, b_finish;
	BluetoothAdapter mBlueAdapt; 
	boolean enablecontrol= false;	
	ArrayAdapter<String> adapter;	
	private BluetoothSocket btSocket = null;
	private OutputStream outStream = null;
	private List<BluetoothDevice> listdevices = new ArrayList<BluetoothDevice>();  
	private static final UUID mUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

	public void enableBluetooth()
	{
		mBlueAdapt = BluetoothAdapter.getDefaultAdapter();

		if(mBlueAdapt!=null){
			mBlueAdapt.enable();			
		}
		else{
			Toast toast = Toast.makeText(getApplicationContext(), "You don't have bluetooth", Toast.LENGTH_SHORT);
			toast.show();
			finish();
		}
	}

	public void searchDevices(){
		mBlueAdapt.startDiscovery();
		Log.d("FreeLabyrinthScreen", "Start Discovery");
	}


	private BroadcastReceiver foundReceiver = new BroadcastReceiver() {
		public void onReceive(Context context, Intent intent) {
			BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
			listdevices.add(device);
			showDevices();			
		}
	};


	private BroadcastReceiver discoveryReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context context, Intent intent)  
		{
			unregisterReceiver(foundReceiver);
			unregisterReceiver(this);
		}
	};


	protected void showDevices()
	{
		list = new ArrayList<String>();
		listView = (ListView)findViewById(R.id.listView1);
		listView.setOnItemClickListener(this);
		if(listdevices.size() > 0)
		{	
			for (int i = 0, size = listdevices.size(); i < size; ++i)
			{
				StringBuilder b = new StringBuilder();
				BluetoothDevice d = listdevices.get(i);
				b.append(d.getName());
				b.append('\n');
				b.append(d.getAddress());
				String s = b.toString();
				list.add(s);
			}
		}
		adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, list);
		listView.setAdapter(adapter);
	}



	public void sendMessage(String message){
		byte[] msgBuffer = message.getBytes();
		Log.i("FreeLabyrinthScreen", "Sent the message: "+message);
		try {
			outStream.write(msgBuffer);
		} catch (IOException e) {
			Log.i("FreeLabyrinthScreen", "Error in sending");
		}
	}


	protected void connect(BluetoothDevice device) {
		try {
			btSocket = device.createRfcommSocketToServiceRecord(mUUID);
		} catch (IOException e) {
			Log.i("FreeLabyrinthScreen", "Failed to create socket.");
		}
		mBlueAdapt.cancelDiscovery();
		try {
			btSocket.connect();
			Log.i("FreeLabyrinthScreen", "Connected to the device");
			Toast toast = Toast.makeText(getApplicationContext(), "Connected", Toast.LENGTH_SHORT);
			toast.show();
		} catch (IOException e) {
			try {
				btSocket.close();
				Log.i("FreeLabyrinthScreen", "Closed socket");
			} catch (IOException e2) {
				Log.i("FreeLabyrinthScreen", "Failed to connect");
				Toast toast = Toast.makeText(getApplicationContext(), "Failed to connect", Toast.LENGTH_SHORT);
				toast.show();
			}
		}
		try {
			outStream = btSocket.getOutputStream();
			Log.i("FreeLabyrinthScreen", "Data Stream created");
		} catch (IOException e) {
			Log.i("FreeLabyrinthScreen", "Failed Data Stream");
		}	
	}

	@Override
	public void onCreate(Bundle savedInstanceState)
	{		
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.free_labyrinth);

		Log.i("FreeLabyrinthScreen", "onCreate FreeLabyrinthScreen");

		enableBluetooth();
		IntentFilter discoveryFilter = new IntentFilter(BluetoothAdapter.ACTION_DISCOVERY_FINISHED);
		registerReceiver(discoveryReceiver, discoveryFilter);
		IntentFilter foundFilter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
		registerReceiver(foundReceiver, foundFilter);
		searchDevices();

		b_start = (Button)findViewById(R.id.button3);
		b_start.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				if(enablecontrol==false){
					Toast toast = Toast.makeText(getApplicationContext(), "You have to connect with the robot", Toast.LENGTH_SHORT);
					toast.show();
				}
				else{
					sendMessage("s");
				}
			}
		});

		b_finish = (Button)findViewById(R.id.button2);
		b_finish.setOnClickListener(new View.OnClickListener() {
			public void onClick(View arg0) {
				if(enablecontrol==false){
					Toast toast = Toast.makeText(getApplicationContext(), "You have to connect with the robot", Toast.LENGTH_SHORT);
					toast.show();	
				}
				else{
					sendMessage("0");
				}
			}
		});


	}

	@Override
	public void onItemClick(AdapterView<?> parent, View view, int position,	long id) {
		BluetoothDevice selectedDevice = listdevices.get(position);
		Log.d("FreeLabyrinthScreen", selectedDevice.toString());
		connect(selectedDevice);		 
		enablecontrol=true;
	}

	protected void onDestroy() {
		super.onDestroy();
		mBlueAdapt.cancelDiscovery();
		Log.i("FreeLabyrinthScreen", "The activity is about to be destroyed.");
	}
} 