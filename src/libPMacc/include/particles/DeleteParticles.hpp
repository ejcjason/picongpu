/**
 * Copyright 2015 Alexander Grund
 *
 * This file is part of libPMacc.
 *
 * libPMacc is free software: you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License or
 * the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libPMacc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License and the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * and the GNU Lesser General Public License along with libPMacc.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace PMacc {
namespace particles {

    /**
     * Policy for HandleGuardParticles that removes all particles from guard cells
     */
    struct DeleteParticles
    {
        /* Particles are removed from the guard cells, hence frames are modified/deleted */
        static const bool needAtomicOut = true;
        /* Nothing is done on incoming side */
        static const bool needAtomicIn  = false;

        template< class T_Particles >
        void
        handleOutgoing(T_Particles& par, int32_t direction) const
        {
            par.deleteGuardParticles(direction);
        }

        template< class T_Particles >
        void
        handleIncoming(T_Particles& par, int32_t direction) const
        {}
    };

}  // namespace particles
}  // namespace PMacc
