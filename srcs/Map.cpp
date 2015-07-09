//
// Map.cpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 11 21:10:26 2015 rousse_3
// Last update Thu Jul  9 17:34:51 2015 rousse_3
//

#include	<fstream>
#include	<sstream>
#include	<iostream>
#include	"Map.hpp"
#include	"Parsing.hpp"
#include	"Error.hpp"

Map::Map(void) : _sizeX(0), _sizeY(0) {}

Map::Map(const std::string &filename)
{
  std::ifstream		in(filename.c_str());

  if (!in)
    throw ParsingError("Error: Cannot opening the file " + filename);
  else
    {
      std::string	error = "";
      std::string	buffer = "";

      std::getline(in, buffer);
      if (getSize(buffer, error) != true)
	throw ParsingError(error + "Error: Cannot get the map size of the file " + filename);
      else
	{
	  if (readMap(in, error) != true)
	    throw ParsingError(error + "Error: Cannot read the map data of the file " + filename);
	  else
	    {
	      showMap();
	    }
	}
    }
}

Map::Map(const Map &copy)
{
  (void) copy;
}

Map::~Map(void) throw() {}

Map		&Map::operator=(const Map &copy)
{
  (void) copy;
  return (*this);
}

bool		Map::getSize(const std::string &buffer, std::string &error)
{
  std::stringstream		ss(buffer);

  ss >> _sizeX >> _sizeY;
  if (ss.gcount() != 0)
    {
      error = "Error: More characters than need in the size of the map\n";
      return (false);
    }
  if (_sizeX <= 0 || _sizeY <= 0)
    {
      error = "Error: Size of the map must be only positive\n";
      return (false);
    }
  return (true);
}

bool		Map::readMap(std::istream &in, std::string &error)
{
  std::string	buffer = "";
  bool		ret = true;

  std::getline(in, buffer);
  while ((ret = getLine(buffer, error)) && in.eof() != true)
    std::getline(in, buffer);
  if (ret == true && _map.size() != _sizeX)
    {
      std::stringstream		ss;

      ss << "Error: Map must have " << _sizeX << " line" << std::endl;
      ss << "       Instead there are " << _map.size() << " line" << std::endl;
      ss >> error;
      ret = false;
    }
  return (ret);
}

bool			Map::checkLine(const std::string &str, std::string &error)
{
  unsigned int		char_idx = 0;
  unsigned int		count_nb = 0;

  while (str[char_idx] != '\0')
    {
      while (isBlank(str[char_idx]))
	char_idx++;
      count_nb++;
      if (isDigit(str[char_idx]) != true)
	{
	  error = "Error: Unexpected char in the map";
	  return (false);
	}
      while (isDigit(str[char_idx]))
	char_idx++;
    }
  if (count_nb != _sizeY)
    {
      std::stringstream		ss;

      ss << "Error: Map must have " << _sizeY << " columns" << std::endl;
      ss << "       Instead there are " << count_nb << " columns" << std::endl;
      ss >> error;
      return (false);
    }
  return (true);
}

bool			Map::getLine(const std::string &str, std::string &error)
{
  int			ret = false;

  if (isLineEmpty(str) == true)
    return  (true);
  if ((ret = checkLine(str, error)) == true)
    {
      std::stringstream	ss(str);
      int			nb;
      std::vector<int>	line;
      unsigned int		count_nb = _sizeY;
      
      while (count_nb > 0)
	{
	  ss >> nb;
	  line.push_back(nb);
	  count_nb--;
	}
      _map.push_back(line);
    }
  return (ret);
}

void					Map::showMap(void) const
{
  std::vector<line>::const_iterator	map_it = _map.begin();
  std::vector<line>::const_iterator	map_end = _map.end();

  while (map_it != map_end)
    {
      bool					begin = true;
      std::vector<int>::const_iterator	line_it = (*map_it).begin();
      std::vector<int>::const_iterator	line_end = (*map_it).end();
      while (line_it != line_end)
	{
	  if (begin != true)
	    std::cout << " ";
	  std::cout << *line_it;
	  begin = false;
	  ++line_it;
	}
      std::cout << std::endl;
      ++map_it;
    }
}
