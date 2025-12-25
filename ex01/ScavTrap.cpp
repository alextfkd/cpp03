/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:51 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 06:37:37 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "ClapTrap.hpp"

ScavTrap::ScavTrap() {
  this->type_          = "ScavTrap";
  this->hit_points_    = ScavTrap::kDefaultHitPoints_;
  this->energy_points_ = ScavTrap::kDefaultEnPoints_;
  this->attack_damage_ = ScavTrap::kDefaultAttackDamages_;
  std::cout << this->getName() << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  this->type_          = "ScavTrap";
  this->hit_points_    = ScavTrap::kDefaultHitPoints_;
  this->energy_points_ = ScavTrap::kDefaultEnPoints_;
  this->attack_damage_ = ScavTrap::kDefaultAttackDamages_;
  std::cout << this->getName() << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  this->type_          = other.type_;
  this->name_          = other.name_;
  this->hit_points_    = other.hit_points_;
  this->energy_points_ = other.energy_points_;
  this->attack_damage_ = other.attack_damage_;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  if (this != &other) {
    this->type_          = other.type_;
    this->name_          = other.name_;
    this->hit_points_    = other.hit_points_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_points_ = other.energy_points_;
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << this->getName() << " destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (!this->checkHitPoints_()) {
    return;
  }
  if (!this->useEnergyPoints_()) {
    return;
  }
  std::cout << this->getName() << " attacks " << target
            << " by throwing knives, causing " << this->attack_damage_
            << " points of damage !" << std::endl;
}

void ScavTrap::guardGate(void) {
  if (!this->checkHitPoints_()) {
    return;
  }
  if (!this->useEnergyPoints_()) {
    return;
  }
  std::cout << this->getName() << " is now in Gate Keeper mode." << std::endl;
}
