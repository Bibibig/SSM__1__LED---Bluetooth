package com.example.led_board;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

//View Ŭ������ ��ӹ��� ����� ���� ��
public class ResultView extends View {

	/*
	// ���� �׸� �� ����� �Ӽ� paint
	private Paint m_paint = null;
	// ���� �׸� ��ǥ�� ������ ����
	private float m_x = -1, m_y = -1;
	 */
	// ���� �׸� �� ����� �Ӽ� paint
	private Paint m_paint = null;
	// ���� �׸� ��ǥ�� ������ ����
	private float m_x = -1, m_y = -1;

	
	// �ҽ��ڵ�� �䰡 �����Ǹ� ȣ��Ǵ� ������
	public ResultView(Context c) {
		super(c);

		// ������ �Ӽ��� ���� Paint ��ü ����
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
	}

	// XML ���ҽ� ���Ϸ� �䰡 �����Ǹ� ȣ��Ǵ� ������
	public ResultView(Context c, AttributeSet attrs) {
		super(c, attrs);

		// ������ �Ӽ��� ���� Paint ��ü ����
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
	}

	// �信 �׸��׸��� ������ ����ϴ� �޼ҵ�
	protected void onDraw(Canvas canvas) {
		// ���� ������ ���������� ĥ�Ѵ�.
		canvas.drawColor(Color.BLUE);

		// ��ġ ������ �߻��� ��� �ش� ��ġ�� ���� �׸���.
		/*
		if (m_x > 0 && m_y > 0 && m_x < 480 && m_y < 480) {
			// (x - 5, y - 5) �� �������� ������ 10�� ���� �׸���.
			//canvas.drawCircle(m_x - 5, m_y - 5, 10, m_paint);
			canvas.drawCircle(m_x - 2, m_y - 2, 4, m_paint);
		}
		*/
	}
/*
	// ��ġ �̺�Ʈ�� ó���ϴ� �ݹ� �޼ҵ�
	public boolean onTouchEvent(MotionEvent event) {
		// ���� Ŭ������ View Ŭ������ �߻��� �̺�Ʈ�� �����Ѵ�.
		super.onTouchEvent(event);

		// � �̺�Ʈ�� �߻��Ͽ������� ���� ó���� �޶�����.
		switch (event.getAction()) {
		// DOWN �̳� MOVE �� �߻��� ���
		case MotionEvent.ACTION_DOWN:
		case MotionEvent.ACTION_MOVE:
			// ��ġ�� �߻��� X, Y �� �� ��ǥ�� ��´�.
			m_x = event.getX();
			m_y = event.getY();

			// �並 �����Ѵ�.
			invalidate();
			break;
		case MotionEvent.ACTION_UP:
			// UP �� �߻��� ��� �׸��� ��ǥ�� -1 �� �����ϰ� �並 �����Ѵ�.
			m_y = m_x = -1;
			invalidate();
			break;
		}
		// true �� ��ȯ�Ͽ� ���̻��� �̺�Ʈ ó���� �̷������ �ʵ��� �̺�Ʈ ó���� �Ϸ��Ѵ�.
		return true;
	}
	*/
}
