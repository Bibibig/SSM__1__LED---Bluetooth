package com.example.led_board;

import java.util.ArrayList;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.graphics.Color;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.TextView;



//Activity 클래스를 상속받은 사용자 정의 액티비티에 OnTouchListener 를 구현한다.
public class TipsDrawableActivity extends Activity implements OnTouchListener {
	// 좌표를 출력할 텍스트뷰
	private TextView m_text_view = null;
	// 터치 위치에 원이 그려지는 사용자 정의 뷰
	private TipsView m_tips_view = null;
	// 터치 위치의 좌표에 사각형이 그려지는 사용자 정의 뷰
	private TipsView m_tips_result_view = null;
	private int [][] visitedArr = new int [32][32];
	

	private static ArrayList<Vertex> arVertex;
	private int i, j;
	
	private static boolean ControlFlag = true;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// XML 파일에 정의한대로 레이아웃을 설정한다.
		setContentView(R.layout.activity_main);

		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

		// 리소스 파일에 정의된 is_tv 라는 ID의 텍스트뷰를 얻어온다.
		m_text_view = (TextView) findViewById(R.id.id_tv);
		// 텍스트뷰에 문자열을 출력한다.
		m_text_view.setText("Touch Touch!!");

		// 리소스 파일에 정의된 id_view 라는 ID 의 사용자정의뷰를 얻어온다.
		m_tips_view = (TipsView) findViewById(R.id.id_view);
		// 사용자정의 뷰에 이 클래스에서 구현한 리스너를 등록한다.
		m_tips_view.setOnTouchListener(this);
		
		// 리소스 파일에 정의된 id_view 라는 ID 의 사용자정의뷰를 얻어온다.
		m_tips_result_view = (TipsView) findViewById(R.id.id_resultview);
		// 사용자정의 뷰에 이 클래스에서 구현한 리스너를 등록한다.
		//m_tips_result_view.setOnTouchListener(this);
		
		arVertex = new ArrayList<Vertex>();
		
	}
	
	public void clickHandler(View target){
		switch (target.getId()) {
		case R.id.write:
			//m_tips_view.setPaintColor(Color.WHITE);
			ControlFlag = true;
			break;

		case R.id.erase:
			ControlFlag = false;
			//m_tips_view.setPaintColor(Color.BLACK);
			//arVertex.get(i).x, arVertex.get(i).y;
			break;

		case R.id.clear:
			m_tips_view.invalidate();
			arVertex.clear();
			//m_tips_view.setPaintColor(Color.WHITE);
			break;
		}
		
	}
	
	public static boolean getControlFlag()
	{
		return ControlFlag;
	}

	public class Vertex{
        float x;
        float y;
        boolean draw;   // 그리기 여부
         
        public Vertex(float x, float y, boolean draw){
            this.x = x;
            this.y = y;
            this.draw = draw;
        }
    }

	// 터치 리스너를 구현하는 onTouch 메소드
	public boolean onTouch(View v, MotionEvent event) {
		// 어떤 이벤트가 발생하였는지에 따라 처리가 달라진다.
		switch (event.getAction()) {
		// DOWN 이나 MOVE 가 발생한 경우
		case MotionEvent.ACTION_DOWN:
		case MotionEvent.ACTION_MOVE:
			
			if(ControlFlag == true)
			{
				arVertex.add(new Vertex(((int)(event.getX()/15))*15, ((int)(event.getY()/15)*15), true));
			}
			// 터치가 발생한 X, Y 의 각 좌표를 얻는다.
			float x = event.getX();
			float y = event.getY();
			
			if(x < 0 || y < 0 || x > 480 || y > 480)
			{
				m_text_view.setText("Touch Touch!!");
				break;
			}
				

			else{
				String str;
				// 좌표값을 이용하여 문자열을 구성한다.
				x = x/15;
				y = y/15;
				visitedArr[(int)x][(int)y] = 1;

				str = "Coordinate : ( " + (int) (x+1) + ", " + (int) (y+1) + " )";
				
				// 구성한 문자열을 텍스트뷰에 출력한다.
				m_text_view.setText(str);


				
				break;
			}
		
				

		case MotionEvent.ACTION_UP:
			// UP 이 발생한 경우 문자를 출력한다.
			//m_text_view.setText("Touch Touch!!");
			//flag=0;
			break;
		}
		// false 를 반환하여 뷰 내에 재정의한 onTouchEvent 메소드로 이벤트를 전달한다.
		return false;
	}
	
	public static ArrayList<Vertex> getArVertex()
	{
		return arVertex;
	}
}
