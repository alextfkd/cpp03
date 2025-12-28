/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:53 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 06:28:18 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 protected:
  const static unsigned int kDefaultHitPoints     = 100;
  const static unsigned int kDefaultEnPoints      = 100;
  const static unsigned int kDefaultAttackDamages = 30;

 public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  virtual ~FragTrap();

  void highFivesGuys(void);
};

#endif
