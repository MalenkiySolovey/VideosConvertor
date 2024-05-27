#include <SFML/Graphics.hpp>     
#include "Headers/Global.h"
#include "Headers/Rectangle.h"
#include "Headers/Text.h"
#include "Headers/Button.h"
#include "Headers/PathSelect.h"
#include <stdlib.h>


int main() {
	loadSet();
	sf::RenderWindow Window(sf::VideoMode(768, 384), "VideoConverter", sf::Style::Close);
	
	//system((_Set::cycle_ + pathIn + _Set::_cycle + _Set::ffmpeg + " -i " + _Set::name + " -q:v 4 -r:v 30 " + pathOut + _Set::nname).c_str());

	Button btnSetPathIn(&Window);
	btnSetPathIn.RCT.setSize(750, 50);
	btnSetPathIn.RCT.setPosCentre(0, -36);
	btnSetPathIn.RCT.setColor(RGB(38, 38, 38), RGB(50, 50, 50));
	btnSetPathIn.TXT.setFont("Files/intelone-mono-font-family-regular.otf");
	btnSetPathIn.TXT.setSize(25);
	btnSetPathIn.TXT.setString(_Set::pathIn);
	btnSetPathIn.TXT.setColor(RGB(255, 255, 255));

	Text txtPathIn(&Window);
	txtPathIn.setString("Folder with videos:");
	txtPathIn.setFont("Files/intelone-mono-font-family-bold.otf");
	txtPathIn.setColor(RGB(0, 0, 0));
	txtPathIn.setSize(25);
	txtPathIn.setPosCentre(0, -86);

	Button btnSetPathOut = btnSetPathIn;
	btnSetPathOut.RCT.setPosCentre(0, -136);
	btnSetPathOut.TXT.setString(_Set::pathOut);

	Text txtPathOut = txtPathIn;
	txtPathOut.setString("Save folder:");
	txtPathOut.setPosCentre(0, -186);

	Button btnConvertAll = btnSetPathIn;
	btnConvertAll.RCT.setSize(280, 50);
	btnConvertAll.RCT.setPosCentre(-200, 30);
	btnConvertAll.RCT.setBorder(10);
	btnConvertAll.TXT.setString("Convert all videos");
	btnConvertAll.TXT.setFont("Files/intelone-mono-font-family-bold.otf");

	Button btnConvertFile = btnConvertAll;
	btnConvertFile.TXT.setString("Convert video");
	btnConvertFile.RCT.setPosCentre(200, 30);

	_bool focus = true;

	while (Window.isOpen()) {
		Window.clear(RGB(255, 255, 255));
		_bool Key_flag{ false };
		sf::Event event;
		while (Window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				saveSet();
				Window.close();
			}
			if (event.type == sf::Event::GainedFocus) {
				focus = true;
			}
			if (event.type == sf::Event::LostFocus) {
				focus = false;
			}
		}

		if (!focus) continue;

		txtPathIn.draw();
		if (btnSetPathIn.draw()) {
			selectPath(_Set::pathIn);
			btnSetPathIn.TXT.setString(_Set::pathIn);
			saveSet();
		}
		txtPathOut.draw();
		if (btnSetPathOut.draw()) {
			selectPath(_Set::pathOut);
			btnSetPathOut.TXT.setString(_Set::pathOut);
			_Set::pathOutff = _Set::pathOut;
			for (_ui64 i = 0; i < _Set::pathOutff.size(); i++)
				if (_Set::pathOutff[i] == '\\') _Set::pathOutff[i] = '/';
			saveSet();
		}
		if (btnConvertAll.draw()) {
			std::string str = "start " + _Set::cycle_ + _Set::pathIn + _Set::_cycle + _Set::ffmpeg + " -i " + _Set::name + " -q:v 4 -r:v 30 " + _Set::pathOutff + _Set::nname;
			system(str.c_str());
		}
		if (btnConvertFile.draw()) {
			std::string path, name, namenew;
			if (selectFile(path)) {
				name = path;
				std::reverse(name.begin(), name.end());
				_ui64 i = 0;
				while (name[i] != '\\') {
					namenew += name[i];
					i++;
				}
				std::reverse(namenew.begin(), namenew.end());
				for (_ui64 i = 0; i < path.size(); i++)
					if (path[i] == '\\') path[i] = '/';
				path = '\"' + path + '\"';
				//std::cout << path << '\n';
				//std::cout << namenew << '\n';

				std::string str = "start " + _Set::ffmpeg + " -i " + path + " -q:v 4 -r:v 30 " + "\"" + _Set::STpathOutff + namenew + "\"";
				std::cout << str << '\n';

				system(str.c_str()); 
			}
		}
		
		Window.display();
	}
	return 0;
}


//Files\ffmpeg.exe -i "C:/Users/sssr2/Pictures/Work/In/view (9).mp4" -q:v 4 -r:v 30 "Save/view (9).mp4"