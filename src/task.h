/***************************************************************************
 *  Copyright (C) 2007 by Saritha Kalyanam                                 *
 *  kalyanamsaritha@gmail.com                                              *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU Affero General Public License as         *
 *  published by the Free Software Foundation, either version 3 of the     *
 *  License, or (at your option) any later version.                        *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU Affero General Public License for more details.                    *
 *                                                                         *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#ifndef __TASK_H__
#define __TASK_H__

#include "dht.h"
#include "pkt.h"
#include "queue.h"
#include "node.h"

enum task_state {
    TASK_STATE_UNKNOWN = 0,
    TASK_STATE_WAIT,
    TASK_STATE_MAX
};

struct task {
    enum task_state                     state;
    u64                                 creation_time;
    u64                                 access_time;
    struct dht                          *dht;
    struct node                         *node;
    TAILQ_HEAD(pkt_list_head, pkt)      pkt_list;
};

int task_new(struct task *task, struct dht *dht, 
                struct node *node, struct pkt *pkt);
size_t task_get_pkt_data_len(struct task *task);

#endif /* __TASK_H__ */
