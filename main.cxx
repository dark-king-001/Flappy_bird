#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
int main(){
	
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Dino runner");

	
	// background
	sf::RectangleShape Background(sf::Vector2f(720.0f,1600.0f));
	Background.setFillColor(sf::Color::Green);
	
	//ground
	sf::RectangleShape ground(sf::Vector2f(720.0f,5.0f));
	ground.setPosition(sf::Vector2f(0.0f,1200.0f));
	ground.setFillColor(sf::Color::Black);
	
	//roof
	sf::RectangleShape roof(sf::Vector2f(720.0f,5.0f));
	roof.setPosition(sf::Vector2f(0.0f,300.0f));
	roof.setFillColor(sf::Color::Black);
	
	//Clock
	sf::Clock clock;
	stringstream ss;
	
	//Score
	sf::RectangleShape Score(sf::Vector2f(350.0f,100.0f));
	Score.setPosition(sf::Vector2f(100.0f,100.0f));
	Score.setFillColor(sf::Color::Cyan);
	Score.setOutlineThickness(5);
	Score.setOutlineColor(sf::Color::Black);
	
	//font
	sf::Font font;
	font.loadFromFile("opensans/OpenSans-ExtraBold.ttf");
	
	//score text
	sf::Text text;
	text.setFont(font);
	text.setPosition(sf::Vector2f(110.0f,100.0f));
	text.setCharacterSize(75);
	text.setColor(sf::Color::Black);
	
	
	// player
	sf::RectangleShape ch(sf::Vector2f(100.0f,80.0f));
	ch.setPosition(sf::Vector2f(50.0f,700.0f));
	
	sf::Texture txt;
	txt.loadFromFile("img1.jpg");
	
	//obstacle 1
	sf::RectangleShape obs1up(sf::Vector2f(150.0f,300.0f));
	sf::RectangleShape obs1down(sf::Vector2f(150.0f,350.0f));
	
	obs1down.setPosition(sf::Vector2f(720.0f,850.0f));
	obs1up.setPosition(sf::Vector2f(720.0f,300.0f));
	
	obs1up.setFillColor(sf::Color::Black);
	obs1down.setFillColor(sf::Color::Black);
	
	//obstacle 2
	sf::RectangleShape obs2up(sf::Vector2f(150.0f,300.0f));
	sf::RectangleShape obs2down(sf::Vector2f(150.0f,350.0f));
	
	obs2down.setPosition(sf::Vector2f(1070.0f,850.0f));
	obs2up.setPosition(sf::Vector2f(1070.0f,300.0f));
	
	obs2up.setFillColor(sf::Color::Black);
	obs2down.setFillColor(sf::Color::Black);
	
	// obstacle 3
	sf::RectangleShape obs3up(sf::Vector2f(150.0f,300.0f));
	sf::RectangleShape obs3down(sf::Vector2f(150.0f,350.0f));
	
	obs3down.setPosition(sf::Vector2f(1420.0f,850.0f));
	obs3up.setPosition(sf::Vector2f(1420.0f,300.0f));
	
	obs3up.setFillColor(sf::Color::Black);
	obs3down.setFillColor(sf::Color::Black);
	
	// obstacle 4
	sf::RectangleShape obs4up(sf::Vector2f(150.0f,300.0f));
	sf::RectangleShape obs4down(sf::Vector2f(150.0f,350.0f));
	
	obs4down.setPosition(sf::Vector2f(1770.0f,850.0f));
	obs4up.setPosition(sf::Vector2f(1770.0f,300.0f));
	
	obs4up.setFillColor(sf::Color::Black);
	obs4down.setFillColor(sf::Color::Black);
	
	// FPS limiter
	window.setFramerateLimit(30);
	//Touch variables
	bool x = false;
	//Event
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			switch (event.type){
				case (sf::Event::Closed):
					window.close();
					break;
				case (sf::Event::TouchBegan):
					x=true;
					break;
				case (sf::Event::TouchEnded):
					x=false;
					break;
			}
		}
		//Display clock
		sf::Time score=clock.getElapsedTime();
		 ss.str(std::string());
        ss << score.asSeconds();
        text.setString( ss.str().c_str() );
		//player Movement
		if (x== true){
			ch.move(0.0,-10.0);
		}
		if (x == false){
			ch.move(0.0,12.0);
		}
		// infinite obstacle
		if (obs1up.getPosition() == sf::Vector2f(-150.0f,300)){
			obs1up.setPosition(sf::Vector2f(1250.0f,300.0f));
			obs1down.setPosition(sf::Vector2f(1250.0f,850.0f));
		}
		if (obs2up.getPosition() == sf::Vector2f(-150.0f,300)){
			obs2up.setPosition(sf::Vector2f(1250.0f,300.0f));
			obs2down.setPosition(sf::Vector2f(1250.0f,850.0f));
		}
		if (obs3up.getPosition() == sf::Vector2f(-150.0f,300)){
			obs3up.setPosition(sf::Vector2f(1250.0f,300.0f));
			obs3down.setPosition(sf::Vector2f(1250.0f,850.0f));
		}
		if (obs4up.getPosition() == sf::Vector2f(-150.0f,300)){
			obs4up.setPosition(sf::Vector2f(1250.0f,300.0f));
			obs4down.setPosition(sf::Vector2f(1250.0f,850.0f));
		}
		
		//obstacle movement
		obs1down.move(-5.0,0.0);
		obs1up.move(-5,0.0);
		
		obs2down.move(-5.0,0.0);
		obs2up.move(-5,0.0);
		
		obs3down.move(-5.0,0.0);
		obs3up.move(-5,0.0);
		
		obs4down.move(-5.0,0.0);
		obs4up.move(-5,0.0);
		
		//usual events
		window.clear();
		window.draw(Background);
		window.draw(ground);
		window.draw(roof);
		window.draw(Score);
		window.draw(text);
		
		
		// obstacle appearance
		window.draw(obs1up);
		window.draw(obs1down);
		
		window.draw(obs2up);
		window.draw(obs2down);
		
		window.draw(obs3up);
		window.draw(obs3down);
		
		window.draw(obs4up);
		window.draw(obs4down);
		
		
		// player animation
		ch.setTexture(&txt);
		window.draw(ch);
		
		window.display();
	}
	return 0;
}