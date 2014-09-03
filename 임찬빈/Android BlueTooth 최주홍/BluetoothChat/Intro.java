package com.example.android.BluetoothChat;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.ImageView;

public class Intro extends Activity {

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.intro);
		ImageView imageview = (ImageView) findViewById(R.id.intro);
		imageview.setOnTouchListener(new OnTouchListener() {

			@Override
			public boolean onTouch(View arg0, MotionEvent arg1) {
				// TODO Auto-generated method stub
				Intent intent = new Intent(getApplicationContext(),
						BluetoothChat.class);
				startActivity(intent);
				finish();
				return false;
			}
		});

	}
	
	@Override
	public void onStart(){
		super.onStart();
	
	}
	
	/*
	protected void onDestroy() {
		super.onDestroy();
	}
	*/
	

}
