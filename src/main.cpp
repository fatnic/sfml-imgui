#include <SFML/Graphics.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello World!");
        ImGui::Button("A button for you!");
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);

        window.draw(circle);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
