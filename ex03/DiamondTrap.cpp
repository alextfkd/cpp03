/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:36:12 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 06:08:06 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name") {
  this->type_          = "DiamondTrap";
  this->name_          = "default";
  this->hit_points_    = DiamondTrap::FragTrap::kDefaultHitPoints_;
  this->energy_points_ = DiamondTrap::ScavTrap::kDefaultEnPoints_;
  this->attack_damage_ = DiamondTrap::FragTrap::kDefaultAttackDamages_;
  std::cout << this->getName() << " constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
  this->type_          = "DiamondTrap";
  this->name_          = name;
  this->hit_points_    = DiamondTrap::FragTrap::kDefaultHitPoints_;
  this->energy_points_ = DiamondTrap::ScavTrap::kDefaultEnPoints_;
  this->attack_damage_ = DiamondTrap::FragTrap::kDefaultAttackDamages_;
  std::cout << this->getName() << " constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other) {
  this->type_          = other.type_;
  this->name_          = other.name_;
  this->hit_points_    = other.hit_points_;
  this->energy_points_ = other.energy_points_;
  this->attack_damage_ = other.attack_damage_;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  if (this != &other) {
    this->type_          = other.type_;
    this->name_          = other.name_;
    this->hit_points_    = other.hit_points_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_points_ = other.energy_points_;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << this->getName() << " destructor called." << std::endl;
}

std::string DiamondTrap::getName(void) const {
  return this->type_ + " " + this->name_;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << this->getName() << " (ClapTrap name: " << ClapTrap::name_ << ")"
            << std::endl;
}
