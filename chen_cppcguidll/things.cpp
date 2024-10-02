#include"cgui.h"
using namespace std;

enum thingType { text, image, progressbar };
typedef pair<int, thingType> thingmapper;

extern vector<thingmapper> mapAllOfThings;
extern vector<basicText> allOfText;
extern vector<basicImage> allOfImage;
extern vector<basicProgressBar> allOfBars;

__declspec(dllexport) basicText __stdcall createText(int row, int column, string _text)
{
	//����һ���ı��ؼ�
	// TODO:�����Ű�
	//1.���ڿؼ����б��з���һ��λ��
	thingmapper tmp = make_pair(allOfText.size(), text);
	mapAllOfThings.push_back(tmp);
	//2.����ؼ�����������ı��ؼ��б���
	basicText ret(_text);
	allOfText.push_back(ret);
	//3.ˢ����Ļ
	refreshScreen();
	//4.���ض���
	return ret;
}

__declspec(dllexport) void __stdcall updateText(basicText& youwant, string _text)
{
	youwant.updateText(_text);
	refreshScreen();
	return;
}

__declspec(dllexport) basicImage __stdcall createImage(int row, int column, vector<string> images)
{
	//TODO:�����Ű�
	//����ͬcreateText
	thingmapper tmp = make_pair(allOfImage.size(), image);
	mapAllOfThings.push_back(tmp);
	basicImage ret(images);
	allOfImage.push_back(images);
	refreshScreen();
	return ret;
}

 __declspec(dllexport) void __stdcall updateImage(basicImage& youwant, vector<string> images)
{
	youwant.updateImage(images);
	refreshScreen();
}

__declspec(dllexport) basicProgressBar __stdcall createProgressBar(int row, int column, int length)
{
	thingmapper tmp = make_pair(allOfBars.size(), progressbar);
	mapAllOfThings.push_back(tmp);
	//TODO:��������ʽ
	basicProgressBar ret(0, length);
	allOfBars.push_back(ret);
	refreshScreen();
	return ret;
}

__declspec(dllexport) void __stdcall updateProgressBar(basicProgressBar& youwant, int progress)
{
	youwant.updateProgress(progress);
	refreshScreen();
	return;
}