
#ifndef MINESWEEPER_CLOCK_H
#define MINESWEEPER_CLOCK_H

#include "header.h"

class Clock
{
public:
	Clock();

    void init();
	void start();
	void stop();
	[[nodiscard]] Uint64 duration(Uint64 divider = 1) const;
    [[nodiscard]] bool isRunning() const { return m_running; };

private:
	Uint64 m_start_timestamp;
    Uint64 m_stop_timestamp;
	Uint64 m_duration;
	bool m_running;

};

#endif
