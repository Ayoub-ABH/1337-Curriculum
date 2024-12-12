/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:12:08 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/11 14:22:23 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string filename;
    std::string new_filename;
    std::string s1;
    std::string s2;
    std::string line;
    std::string content;
    size_t      pos = 0;
    std::string new_content;
    
    if (argc != 4)
    {
        std::cout << "Usage: ./replace filename s1 s2" << std::endl;
        return (1);
    }
    filename = argv[1];
    s1       = argv[2];
    s2       = argv[3];

    if (s1.empty())
    {
        std::cout << "Error: s1 must not be empty" << std::endl;
        return (1);
    }
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }

    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();

    while ((pos = content.find(s1)) != std::string::npos)
    {
        new_content += content.substr(0, pos) + s2;
        content.erase(0, pos + s1.length());
    }
    new_content += content;

    new_filename = filename + ".replace";
    std::ofstream outfile(new_filename);
    if (!outfile)
    {
        std::cout << "Error: could not create file" << std::endl;
        return (1);
    }
    outfile << new_content;
    outfile.close();
    return (0);
}
