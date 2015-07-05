Athlete::Athlete(Athlete::POSITION p, int x, int y)
{
    setPosition(p);
    setX(x);
    setY(y);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

}

int Athlete::getX()
{
    return x;
}

int Athlete::getY()
{
    return y;
}

Athlete::POSITION Athlete::getPosition()
{
    return position;
}

void Athlete::setX(int x)
{
    if(x >= 0 && x <= 9)
    {
        this.x = x;
        //update opengl coordinates
    }
}

void Athlete::setY(int y)
{
    if(y >= 0 && y <= 2)
    {
        this.y = y;
        //we should also update it's opengl coordinates
    }
}

void Athlete::setPostion(Athlete::POSITION p)
{
    position = p;
}

void Athlete::setVertices(GLfloat *v)
{
    //setup scoreboard
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Athlete::Draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
