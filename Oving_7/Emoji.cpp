#include "Emoji.h"

void drawEmojis(Point c, int r, AnimationWindow& win){
    vector<unique_ptr<Emoji>> v;
    v.emplace_back(new SmilingFace(c, r));
    v.emplace_back(new SadFace({c.x+150, c.y}, r));
    v.emplace_back(new AngryFace({c.x+300, c.y}, r));
    v.emplace_back(new WinkingFace({c.x+450, c.y}, r));
    v.emplace_back(new SurprisedFace({c.x+600, c.y}, r));
    for (int i = 0; i < v.size(); i++){
        v.at(i) -> draw(win);
    }
}