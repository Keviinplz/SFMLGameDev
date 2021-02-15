
#include <SFML\Graphics.hpp> // Gain access to the SFML Graphics Library

const int WIDTH = 1024;
const int HEIGHT = 769;

sf::Vector2f viewSize(WIDTH, HEIGHT);

// We will use the VideoMode class from SFML, that sets the width and the height of the windows. It also
// gets the bits that are required to represent a color value in a pixel. The VideoMode also obtains
// the different resolutions that our monitor supports, so that we can let the user set the resolution
// of the game to glorious 4K resolution if they desire.
sf::VideoMode vm(viewSize.x, viewSize.y);

// Now, we can finally create a window. The window is created using the RenderWindow class. The RenderWindow constructor takes
// three paramenters: a VideoMode parameter, a window name parameter, and a Style parameter.
// Style is an enum value, we can add a of values, called a bitmask, to create the window style that we want:
//
// sf::style::Titlebar: This adds a title bar at the top of the window.
// sf::style::Fullscreen: This creates a fullscreen mode window.
// sf::style::Default: This is the default style that combines the ability to resize a window, close it, and add a title bar.
//
// We will create a default-style window
sf::RenderWindow window(vm, "Hello SFML", sf::Style::Default);

// We will create a while loop, which handles the main game loop for our game. This will check whether or not the window is open
// so that we can add some keyboard events by updating and rendering the objects in the scene. The while loop will run
// as long as the window is open.
int main()
{	
    // Initialize Game Objects

    // Setup a Rectangle
    sf::Vector2f rectSize(500.0f, 300.0f);
    sf::RectangleShape rect(rectSize);

    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(viewSize.x / 2, viewSize.y / 2); // Rectangle in middle of the screen
    rect.setOrigin(sf::Vector2f(rectSize.x / 2, rectSize.y / 2)); // Set origin of rectangle to the center of itself

    // Setup a Circle
    float radius = 100.0f;
    sf::CircleShape circle(radius);

    circle.setFillColor(sf::Color::Green);
    circle.setPosition(viewSize.x / 2, viewSize.y / 2);
    circle.setOrigin(sf::Vector2f(radius, radius));

    // Setup a Triangle
    sf::ConvexShape triangle;

    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(-100, 0));
    triangle.setPoint(1, sf::Vector2f(0, -100));
    triangle.setPoint(2, sf::Vector2f(100, 0));

    triangle.setFillColor(sf::Color(128, 0, 128, 255));
    triangle.setPosition(viewSize.x / 2, viewSize.y / 2);

    while (window.isOpen()) {
        // Handle Keyboard Events

        // Update Game Objects in the Scene
        window.clear(sf::Color::Red); // Call .clear before we render the scene
        // Render Game Objects
        window.draw(rect); // We always render objects between .clear and .display members
        window.draw(circle);
        window.draw(triangle);

        window.display(); // Call .display afterward to display the scene objects.
    }
    return 0;
}