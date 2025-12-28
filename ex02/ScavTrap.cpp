/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:51 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 02:52:50 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "ClapTrap.hpp"

ScavTrap::ScavTrap() {
  this->type_          = "ScavTrap";
  this->hit_points_    = ScavTrap::kDefaultHitPoints;
  this->energy_points_ = ScavTrap::kDefaultEnPoints;
  this->attack_damage_ = ScavTrap::kDefaultAttackDamages;
  std::cout << this->getName() << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  this->type_          = "ScavTrap";
  this->hit_points_    = ScavTrap::kDefaultHitPoints;
  this->energy_points_ = ScavTrap::kDefaultEnPoints;
  this->attack_damage_ = ScavTrap::kDefaultAttackDamages;
  std::cout << this->getName() << " parameter constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  *this = other;
  std::cout << this->getName() << " copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  if (this != &other) {
    this->type_          = other.type_;
    this->name_          = other.name_;
    this->hit_points_    = other.hit_points_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_points_ = other.energy_points_;
  }
  std::cout << this->getName() << " copy assignment constructor called."
            << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << this->getName() << " destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (!this->checkHitPoints()) {
    return;
  }
  if (!this->useEnergyPoints()) {
    return;
  }
  std::cout << this->getName() << " attacks " << target
            << " by throwing knives, causing " << this->attack_damage_
            << " points of damage !" << std::endl;
}

void ScavTrap::guardGate(void) {
  if (!this->checkHitPoints()) {
    return;
  }
  if (!this->useEnergyPoints()) {
    return;
  }
  std::cout << this->getName() << " is now in Gate Keeper mode." << std::endl;
}
