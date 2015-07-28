//
// Map.cpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 11 21:10:26 2015 rousse_3
// Last update Fri Jul 10 01:54:39 2015 rousse_3
//

#include	<fstream>
#include	<sstream>
#include	<iostream>
#include	"Map.hpp"
#include	"Parsing.hpp"
#include	"Error.hpp"


static bool		checkLine(const std::string &str, unsigned int sizeY, std::string &error)
{
  unsigned int		charIdx = 0;
  unsigned int		countNb = 0;

  while (str[charIdx] != '\0')
    {
      while (isBlank(str[charIdx]))
	charIdx++;
      countNb++;
      if (isDigit(str[charIdx]) != true)
	{
	  error = "Error: Unexpected char in the map";
	  return (false);
	}
      while (isDigit(str[charIdx]))
	charIdx++;
    }
  if (countNb != sizeY)
    {
      std::stringstream		ss;

      ss << "Error: Map must have " << sizeY << " columns" << std::endl;
      ss << "       Instead there are " << countNb << " columns" << std::endl;
      error = ss.str();
      return (false);
    }
  return (true);
}

static bool		getLine(const std::string &str, unsigned int sizeY, std::vector<std::vector<int> > &map, std::string &error)
{
  int			ret = false;

  if (isLineEmpty(str) == true)
    return  (true);
  if ((ret = checkLine(str, sizeY, error)) == true)
    {
      std::stringstream	ss(str);
      int			nb;
      std::vector<int>	line;
      unsigned int		countNb = sizeY;
      
      while (countNb > 0)
	{
	  ss >> nb;
	  line.push_back(nb);
	  countNb--;
	}
      map.push_back(line);
    }
  return (ret);
}

static bool		readMap(std::istream &in, unsigned int sizeX, unsigned int sizeY, std::vector<std::vector<int> > &map, std::string &error)
{
  std::string	buffer = "";
  bool		ret = true;

  std::getline(in, buffer);
  while ((ret = getLine(buffer, sizeY, map, error)) && in.eof() != true)
    std::getline(in, buffer);
  if (ret == true && map.size() != sizeX)
    {
      std::stringstream		ss;

      ss << "Error: Map must have " << sizeX << " line" << std::endl;
      ss << "       Instead there are " << map.size() << " line" << std::endl;
      error = ss.str();
      ret = false;
    }
  return (ret);
}

Map::Map(void) : _sizeX(0), _sizeY(0), _map() {}

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
	  if (readMap(in, _sizeX, _sizeY, _map, error) != true)
	    throw ParsingError(error + "Error: Cannot read the map data of the file " + filename);
	  else
	    {
	      showMap();
	    }
	}
    }
}

Map::Map(const Map &copy) :
  _sizeX(copy._sizeX),
  _sizeY(copy._sizeY)
{
  std::vector<line>::const_iterator	itLine = copy._map.begin();
  std::vector<line>::const_iterator	endLine = copy._map.end();

  while (itLine != endLine)
    {
      std::vector<int>::const_iterator	itRow = (*itLine).begin();
      std::vector<int>::const_iterator	endRow = (*itLine).end();      
      std::vector<int>			newLine;

      while (itRow != endRow)
	{
	  newLine.push_back(*itRow);
	  ++itRow;
	}
      _map.push_back(newLine);
      ++itLine;
    }
}

Map::~Map(void) throw() {}

Map		&Map::operator=(const Map &copy)
{

  std::vector<line>::const_iterator	itLine = copy._map.begin();
  std::vector<line>::const_iterator	endLine = copy._map.end();

  _sizeX = copy._sizeX;
  _sizeY = copy._sizeY;
  while (itLine != endLine)
    {
      std::vector<int>::const_iterator	itRow = (*itLine).begin();
      std::vector<int>::const_iterator	endRow = (*itLine).end();      
      std::vector<int>			newLine;

      while (itRow != endRow)
	{
	  newLine.push_back(*itRow);
	  ++itRow;
	}
      _map.push_back(newLine);
      ++itLine;
    }
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

void					Map::showMap(void) const
{
  std::vector<line>::const_iterator	mapIt = _map.begin();
  std::vector<line>::const_iterator	mapEnd = _map.end();

  while (mapIt != mapEnd)
    {
      bool				begin = true;
      std::vector<int>::const_iterator	lineIt = (*mapIt).begin();
      std::vector<int>::const_iterator	lineEnd = (*mapIt).end();
      while (lineIt != lineEnd)
	{
	  if (begin != true)
	    std::cout << " ";
	  std::cout << *lineIt;
	  begin = false;
	  ++lineIt;
	}
      std::cout << std::endl;
      ++mapIt;
    }
}
