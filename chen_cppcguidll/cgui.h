#pragma once
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<climits>
#include<map>
using namespace std;

//һЩ��Ҫ��������

void refreshScreen();//����Ҫ�ĺ���������ˢ����Ļ����ʾ�ؼ�
//��Ҫ����ǰֻ֧�ּ򵥶ѵ������Ⱥ�˳��һ���ؼ�һ�У��������е�row��column�ᱻ����

//���ݽṹ

class basicThing //��������
{
public:
	basicThing();
	~basicThing();
	string selfDraw();
	
private:
	
};

class basicText :public basicThing
{
public:
	basicText(string text)
	{
		selfText = text;
	}
	void updateText(string text)
	{
		selfText = text;
	}
	string selfDraw()
	{
		return selfText;
	}
private:
	string selfText;
};

class basicImage:public basicThing
{
public:
	basicImage(vector<string> _imageByLine)
	{
		imageByline = _imageByLine;
	}
	void updateImage(vector<string> _imageByLine)
	{
		imageByline = _imageByLine;
	}
	string selfDraw()
	{
		string lastString = "";
		for (auto kv : imageByline)
		{
			lastString += kv;
			lastString += "\n";
		}
		return lastString;
	}
private:
	vector<string> imageByline;
};

class basicProgressBar :public basicThing
{
public:
	basicProgressBar(int styles,int _length)
	{
		{};
		//��ʽ���֣�TODO

		progress = 0;
		length = _length;
	}
	void updateProgress(int _progress)//��Χ��0-100
	{
		progress = _progress;
	}
	void switchStyle(int styles)
	{
		//TODO
	}
	string selfDraw()
	{
		char beginChar = '[', endChar = ']', fillChar = '=', progressChar = '>', blankChar = ' ';
		//�·�����ʽ����,TODO
		{};
		//�������ʾ
		string result = "";
		result += beginChar;
		result += to_string(progress);
		result += "%";
		for (double i = 1; i < length * (1.0 * progress / 100.0); i += 1)
			result += fillChar;
		if (progress == 100)
			result = result + fillChar + endChar;
		else
		{
			result = result + ">";
			for (double i = 1; i < length * (1.0 * (100-progress) / 100.0); i += 1)
				result += blankChar;
			result += endChar;
		}
		return result;
	}
private:
	int progress;
	int style=-1;
	int length;//�������ĳ���,��λ���ַ���������ͷβ
};


//һЩ����ô��Ҫ�ġ���

//1. �������

basicText createText(int row, int column, string text);
void updateText(basicText& youwant, string text);

//2. ͼƬ���

basicImage createImage(int row, int column, vector<string> image);
void updateImage(basicImage& youwant,vector<string> image);

//3.���������

basicImage createProgressBar(int row, int column);
void updateProgressBar(basicProgressBar& youwant, int progress);

//4.ͨ�ò���

template<typename T>
void changeLocation(T& youwant);