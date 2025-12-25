/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 06:31:20 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap claptrap_a = ClapTrap("alpha");
  ScavTrap scavtrap_b = ScavTrap("bravo");

  std::cout << "ClapTrap Attack test. Alpha cannot attack if it has no energy."
            << std::endl
            << std::endl;
  for (int idx = 0; idx < 12; idx++) {  // NOLINT
    claptrap_a.showStatus();
    claptrap_a.attack(scavtrap_b.getName());
  }

  std::cout
      << std::endl
      << "ScavTrap Attack test. Bravo cannot attack if it has no hit points."
      << std::endl
      << std::endl;
  for (int idx = 0; idx < 7; idx++) {  // NOLINT
    scavtrap_b.showStatus();
    scavtrap_b.attack(scavtrap_b.getName());
    scavtrap_b.takeDamage(24);  // NOLINT
  }
  return 0;
}
