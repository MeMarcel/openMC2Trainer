#include <TGUI/TGUI.hpp>

std::string tabnames[]= {"Misc","Values","Teleporter","Grip","Lightning","NameMod","Matrixer","Carsim","Nitro/Burnout","Gyro","Los Angeles","Paris","Tokio","Nos Changer #1","Nos Changer #2","Skylightning"};

void onTabSelected(tgui::Gui& gui, std::string selectedTab)
{

    for(int i=0; i < 7; i++)
    {
        if( !std::strcmp( selectedTab.c_str(),tabnames[i].c_str())) //strcmp reuturns 0 when equal
        {
            gui.get(tabnames[i])->show();
        }
        else
            gui.get(tabnames[i])->hide();
    }
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(1024, 768), "TGUI Tabs Example");
    tgui::Gui gui{window};

    tgui::Tab::Ptr tabs = tgui::Tab::create();
    tabs->setPosition(20, 20);
    int i;

    for(i=0; i < 7; i++) tabs->add(tabnames[i]); //initial all main tabs

    gui.add(tabs);

    tgui::Panel::Ptr panel;
    for(i=0; i < 7; i++) //initial all panels. u can do this firstwhen added the tabsheet
    {
        panel = tgui::Panel::create();
        panel->setSize(984, 728-tabs->getTabHeight());
        panel->setPosition(tabs->getPosition().x, tabs->getPosition().y + tabs->getTabHeight());
        gui.add(panel, tabnames[i]);
    }
    tabs->connect("TabSelected", onTabSelected, std::ref(gui));
    tabs->select(tabnames[0]);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }

        window.clear();
        gui.draw();
        window.display();
    }
}
