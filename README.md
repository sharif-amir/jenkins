pipeline {
    agent any
    
    stages {
        stage('Build') {
            steps {
                sh 'mvn clean package'
            }
            description: 'Build the code using Maven'
        }
        stage('Unit and Integration Tests') {
            steps {
                sh 'mvn test'
                sh 'mvn verify -P integration-tests'
            }
            description: 'Run unit and integration tests using Maven'
        }
        stage('Code Analysis') {
            steps {
                sh 'mvn checkstyle:checkstyle pmd:pmd findbugs:findbugs'
            }
            description: 'Analyze the code using Checkstyle, PMD, and FindBugs'
        }
        stage('Security Scan') {
            steps {
                sh 'mvn dependency-check:check'
            }
            description: 'Perform a security scan using OWASP Dependency Check'
        }
        stage('Deploy to Staging') {
            steps {
                sh 'ssh user@staging-server "mkdir -p /opt/myapp"'
                sh 'scp target/myapp.war user@staging-server:/opt/myapp'
            }
            description: 'Deploy the application to the staging server'
        }
        stage('Integration Tests on Staging') {
            steps {
                sh 'curl http://staging-server:8080/myapp/health'
            }
            description: 'Run integration tests against the staging environment'
        }
        stage('Deploy to Production') {
            steps {
                sh 'ssh user@prod-server "mkdir -p /opt/myapp"'
                sh 'scp target/myapp.war user@prod-server:/opt/myapp'
            }
            description: 'Deploy the application to the production server'
        }
    }
}
