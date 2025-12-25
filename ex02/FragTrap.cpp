/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:51 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 06:54:58 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include "ClapTrap.hpp"

FragTrap::FragTrap() {
  this->type_          = "FragTrap";
  this->hit_points_    = FragTrap::kDefaultHitPoints_;
  this->energy_points_ = FragTrap::kDefaultEnPoints_;
  this->attack_damage_ = FragTrap::kDefaultAttackDamages_;
  std::cout << this->getName() << " constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  this->type_          = "FragTrap";
  this->hit_points_    = FragTrap::kDefaultHitPoints_;
  this->energy_points_ = FragTrap::kDefaultEnPoints_;
  this->attack_damage_ = FragTrap::kDefaultAttackDamages_;
  std::cout << this->getName() << " constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  this->type_          = other.type_;
  this->name_          = other.name_;
  this->hit_points_    = other.hit_points_;
  this->energy_points_ = other.energy_points_;
  this->attack_damage_ = other.attack_damage_;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  if (this != &other) {
    this->type_          = other.type_;
    this->name_          = other.name_;
    this->hit_points_    = other.hit_points_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_points_ = other.energy_points_;
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << this->getName() << " destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
  if (!this->checkHitPoints_()) {
    return;
  }
  if (!this->useEnergyPoints_()) {
    return;
  }
  std::cout << this->getName() << " says 'Guys!! Give me high-five!!!'."
            << std::endl;
}
