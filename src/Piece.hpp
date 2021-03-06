//
// Created by Krzysiek on 30/01/2022.
//

#ifndef HELLOSFML_PIECE_HPP
#define HELLOSFML_PIECE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Pair.hpp"

enum PieceType
{
	I, J, L, O, S, T, Z
};

class Piece
{
private:
	int length;
public:
	PieceType type;
	std::vector<Pair> cellPositions;
	Pair rotationPoint;
	int howManyRotations;

	Piece(PieceType type, std::vector<Pair> cellPositions, Pair rotationPoint, int howManyRotations, sf::Color color) ;

	std::vector<Pair> GetShapeAfterRotation(int rotation) const;

	int GetLength();

	sf::Color color;
};

#endif //HELLOSFML_PIECE_HPP
