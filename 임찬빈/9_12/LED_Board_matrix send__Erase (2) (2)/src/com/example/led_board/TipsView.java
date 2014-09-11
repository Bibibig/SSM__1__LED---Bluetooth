package com.example.led_board;

import java.util.ArrayList;
import java.util.Iterator;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

import com.example.led_board.TipsDrawableActivity.Vertex;

public class TipsView extends View {

	private int TipsViewX;
	private int TipsViewY;
	private int TipsPartX;
	private int TipsPartY;
	private final int tipsWidth = 32;
	private final int tipsHeight = 16;
	private Bitmap onLed = BitmapFactory.decodeResource(getResources(), R.drawable.ledon);
	private Bitmap offLed = BitmapFactory.decodeResource(getResources(), R.drawable.ledoff);
	
	private boolean backgroundDrawing = false;
	private Paint m_paint = null;

	private int x = -1, y = -1;

	public TipsView(Context c) {
		super(c);
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
	}

	public TipsView(Context c, AttributeSet attrs) {
		super(c, attrs);
		m_paint = new Paint();
		m_paint.setAntiAlias(true);
		m_paint.setColor(Color.WHITE);
	}

	@Override
	protected void onSizeChanged(int w, int h, int oldw, int oldh) {
		super.onSizeChanged(w, h, oldw, oldh);
		TipsViewX = getMeasuredWidth();
		TipsViewY = getMeasuredHeight();
		TipsPartX = TipsViewX / tipsWidth;
		TipsPartY = TipsViewY / tipsHeight;

		Log.i("result", "T : "+TipsViewX + ", "+ TipsViewY);
		onLed = onLed.createScaledBitmap(onLed, TipsPartX, TipsPartY, true);
		offLed = offLed.createScaledBitmap(offLed, TipsPartX, TipsPartY, true);
	}


	public void onBackgroundDraw()
	{
		backgroundDrawing = true;
	}
	
	@Override
	protected void onDraw(Canvas canvas) {
		super.onDraw(canvas);
		canvas.drawColor(Color.BLACK);
		
		ArrayList<Vertex> arVertex = TipsDrawableActivity.getArVertex();
		ArrayList<Vertex> arVertexDel = TipsDrawableActivity.getArVertexDel();
		
		if( backgroundDrawing )
		{
			for (int i = 0; i < arVertexDel.size(); i++) {
				int vx = arVertexDel.get(i).x;
				int vy = arVertexDel.get(i).y;
				
				canvas.drawBitmap(offLed, vx, vy, m_paint);	
			}
			
			backgroundDrawing = false;
		}
		
		boolean ControlFlag = TipsDrawableActivity.getControlFlag();
		boolean areaOfTipsView = x > 0 && y > 0 && x < TipsViewX && y < TipsViewY;

		if (!areaOfTipsView)
			return;
		
		x = (x / TipsPartX) * TipsPartX;
		y = (y / TipsPartY) * TipsPartY;

		if (ControlFlag) {
		
			Iterator<Vertex> it = arVertexDel.iterator();
			while(it.hasNext())
			{
				Vertex v = it.next();
				if(v.x == x && v.y == y)
				{
					it.remove();
					break;
				}
			}

			for (int i = 0; i < arVertexDel.size(); i++)
				canvas.drawBitmap(offLed, arVertexDel.get(i).x, arVertexDel.get(i).y, m_paint);	
			
			for (int i = 0; i < arVertex.size(); i++) 
				canvas.drawBitmap(onLed, arVertex.get(i).x, arVertex.get(i).y, m_paint);
		} 
		
		else {
			
			Iterator<Vertex> it = arVertex.iterator();
			while(it.hasNext())
			{
				Vertex v = it.next();
				if(v.x == x && v.y == y)
				{
					it.remove();
					break;
				}
			}
			
			for (int i = 0; i < arVertexDel.size(); i++)
				canvas.drawBitmap(offLed, arVertexDel.get(i).x, arVertexDel.get(i).y, m_paint);	
			
			for (int i = 0; i < arVertex.size(); i++) 
				canvas.drawBitmap(onLed, arVertex.get(i).x, arVertex.get(i).y, m_paint);	
		}
	}

	// 터치 이벤트를 처리하는 콜백 메소드
	public boolean onTouchEvent(MotionEvent event) {
		super.onTouchEvent(event);

		switch (event.getAction()) {
			case MotionEvent.ACTION_DOWN:
			case MotionEvent.ACTION_MOVE:
				x = (int) event.getX();
				y = (int) event.getY();
	
				boolean areaOfTipsView = x > 0 && y > 0 && x < TipsViewX && y < TipsViewY;

				if (!areaOfTipsView)
					return false;
				else
					invalidate();
	
				break;
			case MotionEvent.ACTION_UP:
				break;
		}

		return true;
	}

	public int getTipsViewX() {
		return TipsViewX;
	}

	public int getTipsViewY() {
		return TipsViewY;
	}
}
