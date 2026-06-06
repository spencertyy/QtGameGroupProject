# CS 6015 — Rain Catcher Game

> A group project for CS 6015 (Software Engineering) at the University of Utah.

![gameplay demo](Kapture%202026-06-05%20at%2019.49.47.gif)

## Team Members
- Katie Stokes
- Spencer Tu
- Terry Cao

## About the Game

Rain Catcher is a Qt-based arcade game where you control a bucket to catch falling water droplets. The game runs for **1 minute** — catch as many droplets as you can before time runs out!

### Features
- **Timed mode** — 1-minute countdown per round
- **Leaderboard** — scores are tracked across sessions
- **Progressive speed** — droplets fall faster as you collect more
- **Sound effects** — audio feedback on catch and miss
- **User accounts** — sign up, log in, or play as guest
- **Birthday greeting** — special message if it's your birthday

## How to Play

- **← →** Arrow keys to move the bucket
- Catch as many droplets as possible before the timer hits 0
- View your score and leaderboard ranking at the end

## How to Build

Requires Qt 6 (install via Homebrew on macOS):

```bash
brew install qt

cd graphicsGame
qmake graphicsGame.pro
make -j4
```

## Course Info

**Course:** CS 6015 — Software Engineering  
**University:** University of Utah  
**Semester:** Spring 2024
