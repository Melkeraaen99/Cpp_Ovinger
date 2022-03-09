#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
    // Definer størrelse på vindu og emoji
};

class Face : public Emoji {
protected:
    Point centre;
    int radius;
public:
    Face(Point c, int r) : centre{c}, radius{r} {}
    // virtual ~Face() {};
    virtual void draw(AnimationWindow& win) override {
        win.draw_circle(centre, radius, Color::yellow);
    }
};

class EmptyFace : public Face {
public:
    EmptyFace(Point c, int r) : Face(c,r) {}
    virtual void draw(AnimationWindow& win) override {
        Face::draw(win);
        win.draw_circle({centre.x-20, centre.y-20}, radius/4, Color::white);  // venstre øye uten fyll (posisjon sett rett på skjerm)
        win.draw_circle({centre.x+20, centre.y-20}, radius/4, Color::white);  // høyre øye uten fyll
        win.draw_circle({centre.x-20, centre.y-20}, radius/8, Color::black);  // venstre øye fyll
        win.draw_circle({centre.x+20, centre.y-20}, radius/8, Color::black);  // høyre øye fyll
    }
};

class SmilingFace : public EmptyFace {
private:
    int width {50};
    int height {20};
    int start_degree{180};
    int end_degree{360};
public:
    SmilingFace(Point c, int r) : EmptyFace(c,r) {}
    virtual void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc({centre.x, centre.y+20}, width, height, start_degree, end_degree, Color::black);
    }
};

class SadFace : public EmptyFace {
private:
    int width {50};
    int height {20};
    int start_degree{0};
    int end_degree{180};
public:
    SadFace(Point c, int r) : EmptyFace(c,r) {}
    virtual void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_arc({centre.x, centre.y+20}, width, height, start_degree, end_degree, Color::black);
    }
};

class AngryFace : public SadFace {
public:
    AngryFace(Point c, int r) : SadFace(c,r) {}
    virtual void draw(AnimationWindow& win) override {
        SadFace::draw(win);
        win.draw_line({centre.x-30, centre.y-38}, {centre.x-5, centre.y-30});
        win.draw_line({centre.x+30, centre.y-38}, {centre.x+5, centre.y-30});
    }
};

class WinkingFace : public Face {
private:
    int width {50};
    int height {20};
    int start_degree{180};
    int end_degree{360};
public:
    WinkingFace(Point c, int r) : Face(c,r) {}
    virtual void draw(AnimationWindow& win) override {
        Face::draw(win);
        win.draw_circle({centre.x-20, centre.y-20}, radius/4, Color::white);  // venstre øye uten fyll
        win.draw_circle({centre.x-20, centre.y-20}, radius/8, Color::black);  // venstre øye fyll
        win.draw_line({centre.x+30, centre.y-25}, {centre.x+10, centre.y-20}); // blunkeøyne
        win.draw_line({centre.x+30, centre.y-15}, {centre.x+10, centre.y-20}); // blunkeøyne
        win.draw_arc({centre.x, centre.y+20}, width, height, start_degree, end_degree, Color::black);
    }
};

class SurprisedFace : public EmptyFace {
public:
    SurprisedFace(Point c, int r) : EmptyFace(c,r) {}
    virtual void draw(AnimationWindow& win) override {
        EmptyFace::draw(win);
        win.draw_circle({centre.x, centre.y+20}, radius/3, Color::black); // Overrasket munn
        win.draw_circle({centre.x, centre.y+20}, radius/4, Color::dark_yellow); // fyll i munnen så den ikke er helt svar
    }
};

void drawEmojis(Point c, int r, AnimationWindow& win);