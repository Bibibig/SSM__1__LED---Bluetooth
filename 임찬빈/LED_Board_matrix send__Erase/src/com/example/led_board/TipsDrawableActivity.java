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



//Activity Ŭ������ ��ӹ��� ����� ���� ��Ƽ��Ƽ�� OnTouchListener �� �����Ѵ�.
public class TipsDrawableActivity extends Activity implements OnTouchListener {
	// ��ǥ�� ����� �ؽ�Ʈ��
	private TextView m_text_view = null;
	// ��ġ ��ġ�� ���� �׷����� ����� ���� ��
	private TipsView m_tips_view = null;
	// ��ġ ��ġ�� ��ǥ�� �簢���� �׷����� ����� ���� ��
	private TipsView m_tips_result_view = null;
	private int [][] visitedArr = new int [32][32];
	

	private static ArrayList<Vertex> arVertex;
	private int i, j;
	
	private static boolean ControlFlag = true;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// XML ���Ͽ� �����Ѵ�� ���̾ƿ��� �����Ѵ�.
		setContentView(R.layout.activity_main);

		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

		// ���ҽ� ���Ͽ� ���ǵ� is_tv ��� ID�� �ؽ�Ʈ�並 ���´�.
		m_text_view = (TextView) findViewById(R.id.id_tv);
		// �ؽ�Ʈ�信 ���ڿ��� ����Ѵ�.
		m_text_view.setText("Touch Touch!!");

		// ���ҽ� ���Ͽ� ���ǵ� id_view ��� ID �� ��������Ǻ並 ���´�.
		m_tips_view = (TipsView) findViewById(R.id.id_view);
		// ��������� �信 �� Ŭ�������� ������ �����ʸ� ����Ѵ�.
		m_tips_view.setOnTouchListener(this);
		
		// ���ҽ� ���Ͽ� ���ǵ� id_view ��� ID �� ��������Ǻ並 ���´�.
		m_tips_result_view = (TipsView) findViewById(R.id.id_resultview);
		// ��������� �信 �� Ŭ�������� ������ �����ʸ� ����Ѵ�.
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
        boolean draw;   // �׸��� ����
         
        public Vertex(float x, float y, boolean draw){
            this.x = x;
            this.y = y;
            this.draw = draw;
        }
    }

	// ��ġ �����ʸ� �����ϴ� onTouch �޼ҵ�
	public boolean onTouch(View v, MotionEvent event) {
		// � �̺�Ʈ�� �߻��Ͽ������� ���� ó���� �޶�����.
		switch (event.getAction()) {
		// DOWN �̳� MOVE �� �߻��� ���
		case MotionEvent.ACTION_DOWN:
		case MotionEvent.ACTION_MOVE:
			
			if(ControlFlag == true)
			{
				arVertex.add(new Vertex(((int)(event.getX()/15))*15, ((int)(event.getY()/15)*15), true));
			}
			// ��ġ�� �߻��� X, Y �� �� ��ǥ�� ��´�.
			float x = event.getX();
			float y = event.getY();
			
			if(x < 0 || y < 0 || x > 480 || y > 480)
			{
				m_text_view.setText("Touch Touch!!");
				break;
			}
				

			else{
				String str;
				// ��ǥ���� �̿��Ͽ� ���ڿ��� �����Ѵ�.
				x = x/15;
				y = y/15;
				visitedArr[(int)x][(int)y] = 1;

				str = "Coordinate : ( " + (int) (x+1) + ", " + (int) (y+1) + " )";
				
				// ������ ���ڿ��� �ؽ�Ʈ�信 ����Ѵ�.
				m_text_view.setText(str);


				
				break;
			}
		
				

		case MotionEvent.ACTION_UP:
			// UP �� �߻��� ��� ���ڸ� ����Ѵ�.
			//m_text_view.setText("Touch Touch!!");
			//flag=0;
			break;
		}
		// false �� ��ȯ�Ͽ� �� ���� �������� onTouchEvent �޼ҵ�� �̺�Ʈ�� �����Ѵ�.
		return false;
	}
	
	public static ArrayList<Vertex> getArVertex()
	{
		return arVertex;
	}
}
