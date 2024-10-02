#pragma once
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<climits>
#include<map>
using namespace std;

//һЩ��Ҫ��������
__declspec(dllexport) void __stdcall refreshScreen();//����Ҫ�ĺ���������ˢ����Ļ����ʾ�ؼ�
	//��Ҫ����ǰֻ֧�ּ򵥶ѵ������Ⱥ�˳��һ���ؼ�һ�У��������е�row��column�ᱻ��
//���ݽṹ

class basicThing //��������
{
public:
	basicThing() {};
	~basicThing() {};
	string __stdcall selfDraw() {};
	
private:
	
};

class basicText :public basicThing
{
public:
	__declspec(dllexport) __stdcall basicText(string text)
	{
		selfText = text;
	}
	__declspec(dllexport) void __stdcall updateText(string text)
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
	__declspec(dllexport) _stdcall basicImage(vector<string> _imageByLine)
	{
		imageByline = _imageByLine;
	}
	__declspec(dllexport) void __stdcall updateImage(vector<string> _imageByLine)
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
	 __declspec(dllexport) _stdcall basicProgressBar(int styles,int _length)
	{
		{};
		//��ʽ���֣�TODO

		progress = 0;
		length = _length;
	}
	__declspec(dllexport) void __stdcall updateProgress(int _progress)//��Χ��0-100
	{
		progress = _progress;
	}
	__declspec(dllexport) void __stdcall switchStyle(int styles)
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

__declspec(dllexport) basicText __stdcall createText(int row, int column, string text);
__declspec(dllexport) void __stdcall updateText(basicText& youwant, string text);

//2. ͼƬ���

__declspec(dllexport) basicImage __stdcall createImage(int row, int column, vector<string> image);
__declspec(dllexport) void __stdcall updateImage(basicImage& youwant, vector<string> image);

//3.���������

__declspec(dllexport) basicProgressBar __stdcall createProgressBar(int row, int column, int length);
__declspec(dllexport) void __stdcall updateProgressBar(basicProgressBar& youwant, int progress);

//4.ͨ�ò���
	
template<typename T>
  void changeLocation(T& youwant);