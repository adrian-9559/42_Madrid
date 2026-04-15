*This project was created as part of the 42 curriculum by <adriescr>.*

# NetPractice

## Short description
NetPractice is a repository of network exercises and labs to learn and test basic and advanced concepts (TCP/UDP sockets, ARP, ICMP, capture/pcap, sniffing, injection and packet handling, etc.). The goal is to provide self-contained exercises, utilities and technical notes to practice in a controlled environment and document results.

## Description
- Objective: enable hands-on learning of networking concepts via incremental exercises and small projects.
- Scope: exercises in C/C++ and Python, automation scripts, example pcap captures, and technical documentation.
- Audience: 42 students, classmates, reviewers and anyone interested in networking.

## Instructions
1. Clone the repository:
	git clone <repo-url>
	cd NetPractice

2. Build and install dependencies (Debian/Ubuntu):
	sudo apt update
	sudo apt install build-essential python3 python3-pip libpcap-dev tcpdump wireshark
	pip3 install scapy

3. Build exercises with Make:
	make -C ejercicios/<exercise>

4. Run exercises:
	- C/C++ programs:
	  sudo ./ejercicios/tcp_server/bin/server
	- Python scripts (sniffer example):
	  sudo python3 ejercicios/sniffer/sniffer.py --interface eth0

5. Training interface
	- The project includes an interface to practice levels (if present in ejercicios/training).
	- Run:
	  ./run.sh
	  or (if the script is in ejercicios/training):
	  cd ejercicios/training
	  ./run.sh
	- Typical parameters:
	  ./run.sh --level N        # start level N
	  ./run.sh --list-levels    # list available levels

6. Export configurations
	- Each level provides an option/utility to export the final configuration to a file (JSON/YAML/pcap).
	- Generic example:
	  ./export_config.sh --level N --output config_levelN.json
	  or from the interface:
	  ./run.sh --export --level N --out ../config_levelN.json
	- Exported files must be placed at the repository root for submission.

## Requirements & submission
- Recommended system: Linux.
- Tools: gcc/g++, make, python3, libpcap, tcpdump, scapy, wireshark.
- Privileges: some exercises require root access for capture/injection of packets.
- Submission requirement: place 10 exported configuration files (one per level) in the repository root. Filenames should be descriptive, for example:
  config_level01.json config_level02.json ... config_level10.json
- Ensure each exercise includes a README with reproducible steps and evidence (screenshots, logs, pcap).

## Typical structure
- README.md — this root file (42 style).
- ejercicios/ — subfolders per exercise (tcp_server, udp_chat, arp_spoof, pcap_capture…).
- scripts/ — utilities and helpers (run.sh, export_config.sh, setup.sh).
- docs/ — notes and references.
- tests/ — automated tests (if applicable).
- config_levelXX.* — exported configuration files (must be placed in the root for submission).

## Best practices
- Run tests in controlled environments (VMs or lab networks).
- Do not interfere with third-party networks without permission.
- Version changes and document each exercise.
- Include clear instructions to reproduce results.

## Resources
- Classic documentation and readings:
  - RFC 791, RFC 792 (IP and ICMP)
  - RFC 793 (TCP), RFC 768 (UDP)
  - Material on ARP and Ethernet (IEEE 802.3)
  - libpcap/pcap manpages and tutorials
  - Scapy documentation: https://scapy.net
  - Wireshark User Guide: https://www.wireshark.org/docs/
  - Articles and tutorials on sniffing, packet injection and network forensics
- Network concepts covered (detailed in exercise docs):
  - TCP/IP addressing, subnet masks and network calculations
  - Default gateway and basic routing
  - Link-layer and network-layer devices: switches and routers
  - OSI layers and mapping to real protocols (Ethernet, IP, TCP/UDP, ARP, ICMP)
  - Packet capture and analysis (pcap), BPF filtering, reconstructing streams
- Use of AI in this project
  - Tool: GitHub Copilot (autocomplete and snippet suggestions).
  - How it was used: suggested README structure, example commands, helper script templates and documentation; texts were reviewed and adapted by the human author.
  - What the AI did not produce: complete exercises were not auto-generated without review; all final code and configurations were reviewed, adapted and tested by the human author.

## Examples
- Build and run example TCP server:
  make -C ejercicios/tcp_server
  sudo ./ejercicios/tcp_server/bin/server
- Capture traffic to a pcap and analyze with Wireshark:
  sudo tcpdump -i eth0 -w capture.pcap
  wireshark capture.pcap

## Contributing
1. Fork the repository.
2. Create a branch feature/my-exercise.
3. Add the exercise with README, Makefile and examples.
4. Open a pull request describing the goal and steps to reproduce.

## License
Project licensed under MIT. Add a LICENSE file if not present.

## Contact
- Open issues in the repository for bugs or improvements.
- For submission review, include the 10 exported configuration files in the root and a README per exercise with verification steps.
