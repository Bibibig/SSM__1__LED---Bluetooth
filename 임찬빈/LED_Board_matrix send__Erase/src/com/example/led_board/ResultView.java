package com.example.led_board;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

//View 클래스를 상속받은 사용자 정의 뷰
public class ResultView extends View {

	/*
	// 원을 그릴 때 사용할 속성 paint
	private Paint m_paint = null;
	// 원을 그릴 좌표를 저장할 변수
	private float m_x = -1, m_y = -1;
	 */
	// 원을 그릴 때 사용할 속성 paint
	private Paint m_paint = null;
	// 원을 그릴 좌표를 저장할 변수
	private float m_x = -1, m_y = -1;

	
	// 소스코드로 뷰가 생성되면 호출되는 생성자
	public ResultView(Context c) {
		super(c);

		// 빨강색 속성을 가진 Paint 객체 생성
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
	}

	// XML 리소스 파일로 뷰가 생성되면 호출되는 생성자
	public ResultView(Context c, AttributeSet attrs) {
		super(c, attrs);

		// 빨강색 속성을 가진 Paint 객체 생성
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
	}

	// 뷰에 그림그리는 행위를 담당하는 메소드
	protected void onDraw(Canvas canvas) {
		// 뷰의 배경색을 검은색으로 칠한다.
		canvas.drawColor(Color.BLUE);

		// 터치 행위가 발생한 경우 해당 위치에 원을 그린다.
		/*
		if (m_x > 0 && m_y > 0 && m_x < 480 && m_y < 480) {
			// (x - 5, y - 5) 를 시작으로 지름이 10인 원을 그린다.
			//canvas.drawCircle(m_x - 5, m_y - 5, 10, m_paint);
			canvas.drawCircle(m_x - 2, m_y - 2, 4, m_paint);
		}
		*/
	}
/*
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

			// 뷰를 갱신한다.
			invalidate();
			break;
		case MotionEvent.ACTION_UP:
			// UP 이 발생한 경우 그리기 좌표에 -1 을 저장하고 뷰를 갱신한다.
			m_y = m_x = -1;
			invalidate();
			break;
		}
		// true 를 반환하여 더이상의 이벤트 처리가 이루어지지 않도록 이벤트 처리가 완료한다.
		return true;
	}
	*/
}
