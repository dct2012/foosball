Athlete::Athlete(Athlete::POSITION p, int x, int y)
{
    setPosition(p);
    setX(x);
    setY(y);

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
    this.x = x;
}

void Athlete::setY(int y)
{
    this.y = y;
}

void Athlete::setPostion(Athlete::POSITION p)
{
    position = p;
}

void Athlete::Draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
