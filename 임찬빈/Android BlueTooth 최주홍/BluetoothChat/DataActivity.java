package com.example.android.BluetoothChat;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class DataActivity extends Activity {

	
	BluetoothChat data = new BluetoothChat();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.data_trans);

		Button trueButton = (Button) findViewById(R.id.button1);
		Button falseButton = (Button) findViewById(R.id.button2);

		trueButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				data.TF_MESSAGE = "1";
				 Log.e("click1", "click1");
				//String trueString = "1";
				//data.sendMessage(trueString);
				//data.setupChat();
				
			}
		});

		falseButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				data.TF_MESSAGE = "2";
				//String falseString = "0";
				//data.sendMessage(falseString);
				//data.setupChat();
			}
		});

	};

}