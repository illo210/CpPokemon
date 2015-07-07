//
// Map.hpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 11 21:08:12 2015 rousse_3
// Last update Tue Jul  7 21:29:06 2015 rousse_3
//

#ifndef					MAP_HPP_
# define				MAP_HPP_

# include				<string>
# include				<vector>

class					Map
{
public:
  Map(void);
  Map(const std::string &filename);
  Map(const Map &copy);
  ~Map(void) throw();

  Map					&operator=(const Map &copy);
private:
  bool					getSize(const std::string &buffer);
  bool					readMap(std::istream &in);
  bool					getLine(const std::string &str);
  bool					checkLine(const std::string &str);

  /*
  ** For debug
  */
  void					showMap(void) const;

  unsigned int				_sizeX;
  unsigned int				_sizeY;
  
  typedef	std::vector<int>	line;
	
  std::vector<line>			_map;
};

// TEST

int					testMap(void);

#endif					/* !MAP_HPP_ */
