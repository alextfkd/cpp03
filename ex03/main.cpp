/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 03:33:03 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void constructorTest() {
  typedef DiamondTrap t;
  std::string         type = "DiamondTrap";
  std::cout << "=== Constructor Test Start ===" << std::endl;
  std::cout << "=== 1. Default Constructor Test ===" << std::endl;
  t instance_0;
  std::cout << type << " 0 name: " << instance_0.getName() << std::endl;

  std::cout << "\n=== 2. Parameter Constructor Test ===" << std::endl;
  t const instance_1("Uno");
  t const instance_2("Dos");
  std::cout << type << " 1 name: " << instance_1.getName() << std::endl;
  std::cout << type << " 2 name: " << instance_2.getName() << std::endl;

  std::cout << "\n=== 3. Copy Constructor Test ===" << std::endl;
  t instance_2copy(instance_2);  // NOLINT
  std::cout << type << " 2 (copy) name: " << instance_2copy.getName()
            << std::endl;

  std::cout << "\n=== 4. Copy Assignment Operator Test ===" << std::endl;
  t const instance_3("Tres");
  t       instance_3copyassigned;
  instance_3copyassigned = instance_3;
  std::cout << type << " 3 name: " << instance_3.getName() << std::endl;
  std::cout << type
            << " 3 (copy-assigned) name: " << instance_3copyassigned.getName()
            << std::endl;
  std::cout << "=== Constructor Test  End ===" << std::endl << std::endl;
}

int main(void) {
  constructorTest();
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
