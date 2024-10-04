#pragma once
#include<map>
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
#include<iostream>
#include<algorithm>
using namespace std;

enum thingType{image,text,progressBar};

struct thingMapper
{
	pair<int, thingType> mapper;
	int row, column;
	thingMapper(pair<int, thingType> x, int row, int column);
};
//typedef pair<int, thingType> thingMapper;
//first������һ���ؼ��ڵ����Ŀؼ��б��е��±�

//��Ҫ������ˢ�¡����ֿؼ�����
string summonFrame();
void refreshScreen();


//�����ؼ�
basicImage*  createImage(int row, int column, vector<string> imageByLine);
basicText*  createText(int row, int column, string text);
basicProgressBar*  createProgressBar(int row, int column, int Length);
//���Ŀؼ�
void  changeImage(basicImage* youwant, vector<string> imageByLine);
void  changeText(basicText* youwant, string text);
void  changeProgress(basicProgressBar* youwant, int progress);

//һЩ������������
//�Ű����
template<typename T> void changeLocation(thingType type, T* thing, int row, int column);