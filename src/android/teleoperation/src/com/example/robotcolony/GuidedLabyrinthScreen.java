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

public class GuidedLabyrinthScreen extends Activity implements OnItemClickListener{

	List<String> list;
	ListView listView;
	BluetoothAdapter mBlueAdapt; 
	boolean enablecontrol= false;	
	ArrayAdapter<String> adapter;	
	private BluetoothSocket btSocket = null;
	private OutputStream outStream = null;
	Button b_up, b_left, b_right, b_down, b_stop;
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
		Log.d("GuidedLabyrinthScreen", "Start Discovery");
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
		Log.i("GuidedLabyrinthScreen", "Sent the message: "+message);
		try {
			outStream.write(msgBuffer);
		} catch (IOException e) {
			Log.i("GuidedLabyrinthScreen", "Error in sending");
		}
	}


	protected void connect(BluetoothDevice device) {
		try {
			btSocket = device.createRfcommSocketToServiceRecord(mUUID);
		} catch (IOException e) {
			Log.i("GuidedLabyrinthScreen", "Failed to create socket.");
		}
		mBlueAdapt.cancelDiscovery();
		try {
			btSocket.connect();
			Log.i("GuidedLabyrinthScreen", "Connected to the device");
			Toast toast = Toast.makeText(getApplicationContext(), "Connected", Toast.LENGTH_SHORT);
			toast.show();
		} catch (IOException e) {
			try {
				btSocket.close();
				Log.i("GuidedLabyrinthScreen", "Closed socket");
			} catch (IOException e2) {
				Log.i("GuidedLabyrinthScreen", "Failed to connect");
				Toast toast = Toast.makeText(getApplicationContext(), "Failed to connect", Toast.LENGTH_SHORT);
				toast.show();
			}
		}
		try {
			outStream = btSocket.getOutputStream();
			Log.i("GuidedLabyrinthScreen", "Data Stream created");
		} catch (IOException e) {
			Log.i("GuidedLabyrinthScreen", "Failed Data Stream");
		}	
	}

	@Override
	public void onCreate(Bundle savedInstanceState)
	{		
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.guided_labyrinth);

		Log.i("GuidedLabyrinthScreen", "onCreate GuidedLabyrinthScreen");

		enableBluetooth();
		IntentFilter discoveryFilter = new IntentFilter(BluetoothAdapter.ACTION_DISCOVERY_FINISHED);
		registerReceiver(discoveryReceiver, discoveryFilter);
		IntentFilter foundFilter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
		registerReceiver(foundReceiver, foundFilter);
		searchDevices();

		b_up = (Button)findViewById(R.id.b_up);
		b_up.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				if(enablecontrol==false){
					Toast toast = Toast.makeText(getApplicationContext(), "You have to connect with the robot", Toast.LENGTH_SHORT);
					toast.show();
				}
				else{
					sendMessage("6");
				}
			}
		});

		b_left = (Button)findViewById(R.id.b_left);
		b_left.setOnClickListener(new View.OnClickListener() {
			public void onClick(View arg0) {
				if(enablecontrol==false){
					Toast toast = Toast.makeText(getApplicationContext(), "You have to connect with the robot", Toast.LENGTH_SHORT);
					toast.show();	
				}
				else{
					sendMessage("4");
				}
			}
		});

		b_right = (Button)findViewById(R.id.b_right);
		b_right.setOnClickListener(new View.OnClickListener() {
			public void onClick(View arg0) {
				if(enablecontrol==false){
					Toast toast = Toast.makeText(getApplicationContext(), "You have to connect with the robot", Toast.LENGTH_SHORT);
					toast.show();		
				}
				else{
					sendMessage("5");
				}
			}
		});

		b_down = (Button)findViewById(R.id.b_down);
		b_down.setOnClickListener(new View.OnClickListener() {
			public void onClick(View arg0) {
				if(enablecontrol==false){
					Toast toast = Toast.makeText(getApplicationContext(), "You have to connect with the robot", Toast.LENGTH_SHORT);
					toast.show();	
				}
				else{
					sendMessage("1");
				}
			}
		});

		b_stop = (Button)findViewById(R.id.b_stop);
		b_stop.setOnClickListener(new View.OnClickListener() {
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
		Log.d("GuidedLabyrinthScreen", "Selected deviced: "+selectedDevice.toString());
		connect(selectedDevice);		 
		enablecontrol=true;
	}

	protected void onDestroy() {
		super.onDestroy();
		mBlueAdapt.cancelDiscovery();
		Log.i("GuidedLabyrinthScreen", "The activity is about to be destroyed.");
	}

} 