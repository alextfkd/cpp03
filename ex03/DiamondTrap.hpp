/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:36:14 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 03:21:41 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include <iostream>
#include <limits>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 protected:
  std::string  name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

  bool checkHitPoints_();
  bool useEnergyPoints_();

 public:
  DiamondTrap();
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap& operator=(const DiamondTrap& other);
  ~DiamondTrap();

  std::string getName(void) const;
  void        attack(const std::string& target);
  void        whoAmI();
};

#endif
