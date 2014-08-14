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

//View Ŭ������ ��ӹ��� ����� ���� ��
public class TipsView extends View {
	
	// ���� �׸� �� ����� �Ӽ� paint
	private Paint m_paint = null;

	// ���� �׸� ��ǥ�� ������ ����
	private float m_x = -1, m_y = -1;
	//private int i = 0;
	
	

	// �ҽ��ڵ�� �䰡 �����Ǹ� ȣ��Ǵ� ������
	public TipsView(Context c) {
		super(c);
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
		// ������ �Ӽ��� ���� Paint ��ü ����
	}
	
	
	public void setPaintColor(int Color)
	{
		this.m_paint.setColor( Color );
	}
	// XML ���ҽ� ���Ϸ� �䰡 �����Ǹ� ȣ��Ǵ� ������
	public TipsView(Context c, AttributeSet attrs) {
		super(c, attrs);

		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
		// ������ �Ӽ��� ���� Paint ��ü ����
	}

	// �信 �׸��׸��� ������ ����ϴ� �޼ҵ�
	protected void onDraw(Canvas canvas) {
		// ���� ������ ���������� ĥ�Ѵ�.
		canvas.drawColor(Color.BLUE);
		ArrayList<Vertex> arVertex = TipsDrawableActivity.getArVertex();
		boolean ControlFlag = TipsDrawableActivity.getControlFlag();
		if(ControlFlag == true)
		{
			// ��ġ ������ �߻��� ��� �ش� ��ġ�� ���� �׸���.
			if (m_x > 0 && m_y > 0 && m_x < 480 && m_y < 480) {
				// (x - 5, y - 5) �� �������� ������ 10�� ���� �׸���.
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

			if(m_x < 0 || m_y < 0 || m_x > 480 || m_y > 480)
			{
				//m_text_view.setText("Touch Touch!!");
				break;
			}
			else
			// �並 �����Ѵ�.
				invalidate();
			break;
		case MotionEvent.ACTION_UP:
			// UP �� �߻��� ��� �׸��� ��ǥ�� -1 �� �����ϰ� �並 �����Ѵ�.
			//m_y = m_x = -1;
			//invalidate();
			break;
		}
		// true �� ��ȯ�Ͽ� ���̻��� �̺�Ʈ ó���� �̷������ �ʵ��� �̺�Ʈ ó���� �Ϸ��Ѵ�.
		return true;
	}
}
