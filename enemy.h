#ifndef GALAGA_ENEMY
  #define GALAGA_ENEMY

  #include <allegro5/allegro.h>
  #include <allegro5/allegro_audio.h>
  #include <allegro5/allegro_image.h>
  #include <allegro5/allegro_primitives.h>
  #include <cmath>
  #include <iostream>
  #include <list>

  #include "bullet.h"
  #include "ship.h"
  #include "utilities.h"

  #define GALAGA_ENEMY_STATE_MOVE 0
  #define GALAGA_ENEMY_STATE_GROW 1
  #define GALAGA_ENEMY_STATE_STRIKE 2

  class Enemy {
    Rectangle _container;

    ALLEGRO_BITMAP *_texture = NULL;

    std::string _sample;

    float _growX = 0.0;
    float _growY = 0.0;

    float _growRateX = 0.0;
    float _growRateY = 0.0;

    Point _initialPosition;

    int _xSpeed = 3;

    int _fireRate;

    bool _alive;
    int _enemyType;
    int _frame = 0;

    int _previousState = NULL;
    int _currentState = GALAGA_ENEMY_STATE_MOVE;

    bool _needsFire = false;

    unsigned int _stateTicks;

  public:
    Enemy();
    Enemy(int x, int y, ALLEGRO_BITMAP *texture, int enemyType, std::string sample);
    ~Enemy();

    bool update(unsigned int ticks);
    void render();

    Rectangle getContainer() { return _container; }

    void decideShot(Ship ship);
    void trigger() { _needsFire = true; }
    bool needsFire() { return _needsFire; }
    void fire() { _needsFire = false; }

    bool isAlive() { return _alive; }
    std::string getSample() { return _sample; }

    int getPointsWorth();

    void kill() { _alive = false; }
    void vivify() { _alive = false; }

    bool hitTest(std::list<Bullet> *bullets);

    void moveTo(int x, int y);
  };
#endif
