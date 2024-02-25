# 0x09. Web infrastructure design

## Description

This project contains links to diagrams representing different web infrastructures.
Its goal is to understand, on a very high-level, how web infrastructures are organized and what are their components.

# Infrastructure Design:

## User Accessing the Website:
A user types www.foobar.com into their web browser.

## Domain Name (DNS):
The domain name www.foobar.com is configured with a www record that points to the server's IP address, which is 8.8.8.8.
The DNS server translates the domain name www.foobar.com to the corresponding IP address (8.8.8.8) so that the user's browser can locate the server.

## Server:
The server (with IP address 8.8.8.8) hosts the entire web infrastructure.
It's a physical or virtual machine responsible for running the necessary software to handle incoming requests and serve the website.

## Web Server (Nginx):
Nginx is installed on the server and acts as the web server.
Its role is to receive HTTP requests from clients (browsers), forward them to the application server, and send the response back to the client.

## Application Server:
An application server (e.g., Gunicorn for Python applications) is installed on the server.
It runs the application code (your code base) and processes dynamic content generation, handling user requests, executing application logic, and generating responses.

## Application Files (Code Base):
The application files, which contain the code for the website, are stored on the server.
These files are executed by the application server to generate dynamic content for the website.

## Database (MySQL):
MySQL is installed on the server and acts as the database server.
It stores and manages the website's data, such as user accounts, content, and configurations.

## User-Server Communication:
When the user requests www.foobar.com, their browser sends an HTTP request to the server's IP address (8.8.8.8).
The request is received by the web server (Nginx), which forwards it to the application server.
The application server processes the request, retrieves or manipulates data from the database if necessary, generates a response, and sends it back to the web server.
Finally, the web server returns the response to the user's browser, which renders the website.

# Issues of 0-simple_web_stack
## Single Point of Failure (SPOF):
The entire infrastructure relies on a single server. If the server fails, the website becomes inaccessible.
To mitigate this, you could implement redundancy by using multiple servers with load balancing and failover mechanisms.

## Downtime during Maintenance:
When maintenance is needed (e.g., deploying new code), the web server (Nginx) may need to be restarted, causing downtime for the website.
This downtime can be reduced by implementing rolling updates, where servers are updated one at a time without interrupting service.

## Scalability Issues:
The infrastructure may struggle to handle a large influx of incoming traffic, as it's limited to a single server.
Scaling horizontally by adding more servers and distributing the workload can address this issue. Additionally, using caching mechanisms and content delivery networks (CDNs) can help improve performance and scalability.

# Issues of 1-distributed_web_infrastructure
## Single Point of Failure (SPOF):
The load balancer, web servers, application server, and database server could each become single points of failure.
Implementing redundancy, failover mechanisms, and monitoring is essential to mitigate this risk.

## Security Issues:
There is no mention of firewall configurations or HTTPS encryption, leaving the infrastructure vulnerable to security threats.
Implementing firewalls, HTTPS encryption, and security best practices is necessary to protect sensitive data and ensure secure communication.

## No Monitoring:
Without proper monitoring and alerting mechanisms, it would be challenging to detect and respond to performance issues, failures, or security breaches.
Implementing monitoring tools and practices helps ensure the health, performance, and security of the infrastructure.

# Issues of 2-secured_and_monitored_web_infrastructure
## Terminating SSL at Load Balancer Level:
Terminating SSL at the load balancer level can be an issue because it exposes decrypted traffic within the internal network.
To mitigate this risk, you can implement end-to-end encryption by encrypting traffic between the load balancer and web servers using SSL.

## Single MySQL Server for Writes:
Having only one MySQL server capable of accepting writes can be a single point of failure.
To improve fault tolerance and reliability, you can implement MySQL replication and clustering to distribute write operations across multiple servers.

## Uniform Server Components:
Having servers with all the same components (database, web server, and application server) might be a problem as it increases the risk of a single vulnerability affecting multiple servers.
To enhance security and mitigate risks, you can diversify server components and configurations, implement patch management, and regularly update software and firmware.
