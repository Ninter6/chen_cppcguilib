#include"cgui.h"
using namespace std;

vector<thingMapper> allThings;
vector<basicImage> allImage;
vector<basicText> allText;
vector<basicProgressBar> allProgressBars;


//todo:�����Ű�
string summonFrame()
{
	string finalFrame = "";
	for (auto kv : allThings)
	{
		switch (kv.second)
		{

		case image:
			finalFrame += allImage[kv.first].selfDraw();//���ﲻ�ӻ��з�����ΪbasicImage��selfDraw()���л�����
			break;
		case progressBar:
			finalFrame = finalFrame + allProgressBars[kv.first].selfDraw() + '\n';
			break;
		case text:
			finalFrame = finalFrame + allText[kv.first].selfDraw() + '\n';
			break;
		default:
			break;
		}
	}
	return finalFrame;
}

void refreshScreen()
{
	string frame = summonFrame();
	system("cls");//����windows(msvc),��ʱ�����Ǽ���Linux���֧��
	cout << frame;
	return;
}

//create��غ�������Ҫע��������е��Ű���ز���(row/column)���ᱻ���ԣ���δ���������ع���
basicImage*  createImage(int row, int column, vector<string> imageByLine)
{
	basicImage returnThing(imageByLine);
	thingMapper thisThing = make_pair(allImage.size(),thingType::image);
	allImage.push_back(returnThing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allImage[allImage.size()-1];
}

basicText*  createText(int row, int column, string text)
{
	basicText returnThing(text);
	thingMapper thisThing = make_pair(allText.size(), thingType::text);
	allText.push_back(returnThing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allText[allText.size() - 1];
}

basicProgressBar*  createProgressBar(int row, int column, int length)
{
	basicProgressBar returnthing(length, 0);//�ı���ʽ������δ������
	thingMapper thisThing = make_pair(allProgressBars.size(), thingType::progressBar);
	allProgressBars.push_back(returnthing);
	allThings.push_back(thisThing);
	refreshScreen();
	return &allProgressBars[allProgressBars.size() - 1];
}

//change��غ���
void  changeImage(basicImage* youwant, vector<string> imageByLine)
{
	youwant->changeImage(imageByLine);
	refreshScreen();
	return;
}

void  changeProgress(basicProgressBar* youwant, int progress)
{
	youwant->updateProgress(progress);
	refreshScreen();
	return;
}

void changeText(basicText* youwant, string text)
{
	youwant->changeText(text);
	refreshScreen();
	return;
}