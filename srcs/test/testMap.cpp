//
// testMap.cpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jul  7 21:27:11 2015 rousse_3
// Last update Thu Jul  9 16:49:30 2015 rousse_3
//

#include		"Map.hpp"
#include		"Error.hpp"
#include		<iostream>

int			testMap(void)
{
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/littleMapValid");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/emptyLine");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/badNumberColumns");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/badNumberRows");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/badNumberColumnsBis");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/badNumberRowsBis");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  try
    {
      Map			("maps/inexistantFile");
    }
  catch (const PokemonError &error)
    {
      std::cerr << error.what() << std::endl;
      std::cerr << error.where() << std::endl;
    }
  std::cout << "###############################################################################" << std::endl;
  return (0);
}
