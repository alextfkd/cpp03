/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 05:36:23 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap    claptrap_a    = ClapTrap("alpha");
  DiamondTrap diamondtrap_d = DiamondTrap("delta");
  std::cout << std::endl;
  std::cout << std::endl << "DiamondTrap test." << std::endl << std::endl;
  for (int idx = 0; idx < 7; idx++) {  // NOLINT
    diamondtrap_d.showStatus();
    diamondtrap_d.attack(claptrap_a.getName());
    diamondtrap_d.highFivesGuys();
    diamondtrap_d.guardGate();
    diamondtrap_d.takeDamage(24);  // NOLINT
    diamondtrap_d.whoAmI();
  }
  std::cout << std::endl;
  return 0;
}
