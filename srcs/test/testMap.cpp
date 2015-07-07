//
// testMap.cpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jul  7 21:27:11 2015 rousse_3
// Last update Tue Jul  7 21:45:45 2015 rousse_3
//

#include		"Map.hpp"
#include		<iostream>

int			testMap(void)
{
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/littleMapValid");
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/emptyLine");
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/badNumberColumns");
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/badNumberRows");
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/badNumberColumnsBis");
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/badNumberRowsBis");
  std::cout << "###############################################################################" << std::endl;
  Map			("maps/inexistantFile");
  std::cout << "###############################################################################" << std::endl;
  return (0);
}
