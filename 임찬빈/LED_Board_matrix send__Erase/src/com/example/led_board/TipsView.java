package com.example.led_board;

import java.util.ArrayList;

import com.example.led_board.TipsDrawableActivity.Vertex;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

//View 클래스를 상속받은 사용자 정의 뷰
public class TipsView extends View {
	
	// 원을 그릴 때 사용할 속성 paint
	private Paint m_paint = null;

	// 원을 그릴 좌표를 저장할 변수
	private float m_x = -1, m_y = -1;
	//private int i = 0;
	
	

	// 소스코드로 뷰가 생성되면 호출되는 생성자
	public TipsView(Context c) {
		super(c);
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
		// 빨강색 속성을 가진 Paint 객체 생성
	}
	
	
	public void setPaintColor(int Color)
	{
		this.m_paint.setColor( Color );
	}
	// XML 리소스 파일로 뷰가 생성되면 호출되는 생성자
	public TipsView(Context c, AttributeSet attrs) {
		super(c, attrs);

		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
		// 빨강색 속성을 가진 Paint 객체 생성
	}

	// 뷰에 그림그리는 행위를 담당하는 메소드
	protected void onDraw(Canvas canvas) {
		// 뷰의 배경색을 검은색으로 칠한다.
		canvas.drawColor(Color.BLUE);
		ArrayList<Vertex> arVertex = TipsDrawableActivity.getArVertex();
		boolean ControlFlag = TipsDrawableActivity.getControlFlag();
		if(ControlFlag == true)
		{
			// 터치 행위가 발생한 경우 해당 위치에 원을 그린다.
			if (m_x > 0 && m_y > 0 && m_x < 480 && m_y < 480) {
				// (x - 5, y - 5) 를 시작으로 지름이 10인 원을 그린다.
				//canvas.drawCircle(m_x - 5, m_y - 5, 10, m_paint);
				m_x = (float)((int)(m_x/15));
				m_y = (float)((int)(m_y/15));
				m_x = m_x*15;
				m_y = m_y*15;

				for(int i=0; i< arVertex.size(); i++){
					canvas.drawRect(arVertex.get(i).x, arVertex.get(i).y, arVertex.get(i).x+15, arVertex.get(i).y+15, m_paint);
	            }
				//canvas.drawRect(m_x, m_y, m_x+30, m_y+30, m_paint);
			}
			
		}
		else if(ControlFlag == false)
		{
			m_x = (float)((int)(m_x/15));
			m_y = (float)((int)(m_y/15));
			m_x = m_x*15;
			m_y = m_y*15;
			for(int i=0; i< arVertex.size(); i++){
				if(arVertex.get(i).x == m_x && arVertex.get(i).y ==m_y){
					arVertex.remove(i);
				}
				
            }
			for(int i=0; i< arVertex.size(); i++){
				canvas.drawRect(arVertex.get(i).x, arVertex.get(i).y, arVertex.get(i).x+15, arVertex.get(i).y+15, m_paint);
            }
			
		}
	}

	// 터치 이벤트를 처리하는 콜백 메소드
	public boolean onTouchEvent(MotionEvent event) {
		
		// 상위 클래스인 View 클래스에 발생한 이벤트를 전달한다.
		super.onTouchEvent(event);

		// 어떤 이벤트가 발생하였는지에 따라 처리가 달라진다.
		switch (event.getAction()) {
		// DOWN 이나 MOVE 가 발생한 경우
		case MotionEvent.ACTION_DOWN:
		case MotionEvent.ACTION_MOVE:
			// 터치가 발생한 X, Y 의 각 좌표를 얻는다.
			
			m_x = event.getX();
			m_y = event.getY();

			if(m_x < 0 || m_y < 0 || m_x > 480 || m_y > 480)
			{
				//m_text_view.setText("Touch Touch!!");
				break;
			}
			else
			// 뷰를 갱신한다.
				invalidate();
			break;
		case MotionEvent.ACTION_UP:
			// UP 이 발생한 경우 그리기 좌표에 -1 을 저장하고 뷰를 갱신한다.
			//m_y = m_x = -1;
			//invalidate();
			break;
		}
		// true 를 반환하여 더이상의 이벤트 처리가 이루어지지 않도록 이벤트 처리가 완료한다.
		return true;
	}
}
