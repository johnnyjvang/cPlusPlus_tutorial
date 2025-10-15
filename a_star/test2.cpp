#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

const int ROWS = 20;
const int COLS = 20;
const int CELL_SIZE = 30;

enum class Cell { Empty, Obstacle, Start, Goal, Path };

std::vector<std::vector<Cell>> GenerateGrid(int rows, int cols, double obstacle_prob = 0.3) {
    std::vector<std::vector<Cell>> grid(rows, std::vector<Cell>(cols, Cell::Empty));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(obstacle_prob);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            grid[i][j] = d(gen) ? Cell::Obstacle : Cell::Empty;

    grid[0][0] = Cell::Start;
    grid[rows - 1][cols - 1] = Cell::Goal;
    return grid;
}

sf::Color GetCellColor(Cell c) {
    switch (c) {
        case Cell::Empty: return sf::Color::White;
        case Cell::Obstacle: return sf::Color::Black;
        case Cell::Start: return sf::Color::Green;
        case Cell::Goal: return sf::Color::Red;
        case Cell::Path: return sf::Color::Yellow;
    }
    return sf::Color::White;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(COLS * CELL_SIZE, ROWS * CELL_SIZE), "A* Visualizer (Step 1)");
    auto grid = GenerateGrid(ROWS, COLS);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw grid
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
                cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                cell.setFillColor(GetCellColor(grid[i][j]));
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
