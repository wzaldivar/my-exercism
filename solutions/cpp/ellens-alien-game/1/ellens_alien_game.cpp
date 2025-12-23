namespace targets
{
    // TODO: Insert the code for the alien class here

    class Alien
    {
    private:
        int health;

    public:
        int x_coordinate;
        int y_coordinate;

        Alien(int x, int y) : x_coordinate(x), y_coordinate(y)
        {
            this->health = 3;
        }

        int get_health() const { return this->health; }

        bool hit()
        {
            if (this->health > 0)
            {
                this->health--;
            }

            return true;
        }

        bool is_alive() const { return this->health > 0; }

        bool teleport(int x, int y)
        {
            this->x_coordinate = x;
            this->y_coordinate = y;

            return true;
        }

        bool collision_detection(Alien &other)
        {
            return this->x_coordinate == other.x_coordinate && this->y_coordinate == other.y_coordinate;
        }
    };

} // namespace targets