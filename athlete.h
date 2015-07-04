class Athlete
{
    private:
        POSITION position;
        int x, y;
        GLuint VBO, VAO, EBO;

    public:
        Athlete(POSITION p, int x, int y);

        enum POSITION {QB, RECIEVER, DEFENSE, BALL};

        int getX();
        int getY();
        POSITION getPosition();
        
        void setX(int x);
        void setY(int y);
        void setPosition(POSITION p);

        void Draw();
};
