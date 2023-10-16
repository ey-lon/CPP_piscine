/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:28 by abettini          #+#    #+#             */
/*   Updated: 2023/10/11 09:45:42 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	ft_findAndReplace(std::ifstream *fileIn, std::ofstream *fileOut, std::string strToFind, std::string strToReplace)
{
	std::string buff;
	int			i;
	int			j;

	buff.erase();
	getline(*fileIn, buff, '\0');
	if (buff.empty())
		return;
	i = 0;
	j = 0;
	while (i != -1)
	{
		i = buff.find(strToFind, i);
		if (i == -1)
			*fileOut << &buff[j];
		else
		{
			//copy-------
			while (j < i)
			{
				*fileOut << buff[j];
				j++;
			}
			//replace----
			*fileOut << strToReplace;
			//skip-------
			j += strToFind.length();
			i += strToFind.length();
		}
	}

}

int main(int ac, char **av)
{
	//arg_check----------
	if (ac != 4 || !*av[2])
	{
		std::cerr << "Error" << std::endl;
		std::cout << "execution: ./Sed <filename> <non-empty string1> <string2>" << std::endl;
		return (1);
	}
	
	//Infile-------------
	std::string fileInStr(av[1]);
	std::ifstream fileIn(fileInStr.c_str());
	if (!fileIn)
	{
		std::cerr << "Error: No such file: " << fileInStr << std::endl;
		return (1);
	}

	//Outfile------------
	std::string fileOutStr = fileInStr + ".replace";
	std::ofstream fileOut(fileOutStr.c_str());
	if (!fileOut)
	{
		std::cerr << "Error: Couldn't create " << fileOutStr << std::endl;
		return (1);
	}
	
	//find_and_replace---
	std::string strToFind(av[2]);
	std::string strToReplace(av[3]);
	ft_findAndReplace(&fileIn, &fileOut, strToFind, strToReplace);

	//close--------------
	fileOut.close();
	fileIn.close();

	return (0);
}
