package com.example.robotcolony;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.Toast;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.util.Log;

public class MainActivity extends Activity {

	private final String TAG = "RobotColony";
	BluetoothAdapter mBlueAdapt;

	@Override
	protected void onCreate(Bundle savedInstanceState) {

		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.activity_main);


		final Button guidedLabyrinth = (Button) findViewById(R.id.button1);
		final Button freeLabyrinth = (Button) findViewById(R.id.button2);
		final Button exit = (Button) findViewById(R.id.button3);


		mBlueAdapt = BluetoothAdapter.getDefaultAdapter();
		if(mBlueAdapt!=null){
			mBlueAdapt.enable();			
		}
		else{
			Toast toast = Toast.makeText(getApplicationContext(), "You don`t have bluetooth", Toast.LENGTH_SHORT);
			toast.show();
			finish();
		}

		guidedLabyrinth.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Intent guidedLabyrinthIntent = new Intent(MainActivity.this,GuidedLabyrinthScreen.class);
				startActivity(guidedLabyrinthIntent);
			}
		});

		freeLabyrinth.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Intent freeLabyrinthIntent = new Intent(MainActivity.this,FreeLabyrinthScreen.class);
				startActivity(freeLabyrinthIntent);
			}
		});

		exit.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				mBlueAdapt.disable();
				finish();
				System.exit(0);
			}
		});
	}


	@Override
	protected void onDestroy() {
		super.onDestroy();
		mBlueAdapt.disable();
		Log.i(TAG, "The activity is about to be destroyed.");
	}
}