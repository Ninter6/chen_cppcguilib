#pragma once
#include<map>
#include"basicImage.h"
#include"basicProgressBar.h"
#include"basicText.h"
#include"basicthing.h"
using namespace std;

enum thingType{image,text,progressBar};

typedef pair<int, thingType> thingMapper;
//first������һ���ؼ��ڵ����Ŀؼ��б��е��±�

//��Ҫ������ˢ�¡����ֿؼ�����
string summonFrame();
void refreshScreen();


//�����ؼ�
basicImage createImage(int row, int column, vector<string> imageByLine);
basicText createText(int row, int column, string text);
basicProgressBar createProgressBar(int row, int column, int Length);
//���Ŀؼ�
void changeImage(basicImage& youwant, vector<string> imageByLine);
void changeText(basicText& youwant, string text);
void changeProgress(basicProgressBar& youwant, int progress);

//һЩ������������
//TODO