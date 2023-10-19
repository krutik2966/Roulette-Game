# Roulette Game

<p align="center">
<img src="https://t3.ftcdn.net/jpg/03/00/20/62/240_F_300206258_b1RhGTAJqFyKOtFSnqE3yrT2Ps3PIntj.jpg" width="700" height="250" border="10"/>
</p>

## Table of Contents
1. [Description](#description)
2. [Classes](#classes)
    - [Bet](#bet)
    - [Bin](#bin)
    - [BinBuilder](#binbuilder)
    - [Game](#game)
    - [Outcome](#outcome)
    - [Player](#player)
    - [Table](#table)
    - [Wheel](#wheel)

---

## Description

The Roulette Game is an application that simulates the popular casino game of roulette. Roulette is a game of chance where players place bets on various outcomes, and a spinning wheel with numbered pockets determines the results. This project provides a set of classes to model and simulate the game, including bets, outcomes, players, and the game itself.

The project is designed to be flexible and extendable, allowing for various betting strategies, player interactions, and game configurations.

Reference: [Building Skills in Object-Oriented Design](https://slott56.github.io/building-skills-oo-design-book/build/html/index.html)

---

## Classes

### Bet

The `Bet` class represents a wager placed by a player on a specific outcome. It includes information about the amount of the bet and the outcome it's associated with. 

### Bin

The `Bin` class represents an outcome or a possible result of a roulette spin. Each bin is associated with a specific set of numbers or colors. Bins are used to determine the winning outcome after a wheel spin.

### BinBuilder

The `BinBuilder` class is responsible for constructing the bins for a roulette wheel. It calculates and assigns outcomes to each bin based on the wheel's configuration.

### Game

The `Game` class serves as the core of the roulette game simulation. It manages the wheel, players, and bets. It allows players to place bets, spin the wheel, and determine the winning outcome. Players can be added or removed from the game, and the game's rules and variations can be customized.

### Outcome

The `Outcome` class represents a specific result that players can bet on in roulette. Outcomes are associated with bins on the wheel and have a name and odds that determine the payout for winning bets.

### Player

The `Player` class models a player participating in the roulette game. Players can place bets, check their balance, and interact with the game. Various strategies and behaviors for players can be implemented using this class.

### Table

The `Table` class represents the betting table in the roulette game. It defines the available betting options, their minimum and maximum bet limits, and tracks the players' bets.

### Wheel

The `Wheel` class models the spinning wheel used in roulette. It contains a collection of bins, and when spun, it randomly selects one bin to determine the winning outcome. The wheel's configuration, including the number of bins and their distribution, can be customized to simulate different variants of roulette.
