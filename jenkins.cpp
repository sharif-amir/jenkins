pipeline {
    agent any
    environment {
        DIRECTORY_PATH= "The path of the code directory being fetched"
        TESTING_ENVIRONMENT= "pipeline"
        PRODUCTION_ENVIRONMENT= "Sharif"
        EMAIL_RECIPIENT= "4sharifamiri@gmail.com"
    }
    stages{
        stage("Build"){
            steps{
                echo "Build started and completed!"
                echo "Fetch the source code from the directory path specified by the environment variable"
            }
        }
        stage("Test"){
            steps{
                echo "Test started and completed!"
                echo "Running unit tests and integration tests"
            }
        }
        stage("Code Quality Check"){
            steps{
                echo "Code Quality Check started and completed!"
                echo "Check the quality of the code"
            }
        }
        stage("Deploy"){
            steps{
                echo "Deploy started and completed!"
                echo "Deploy the application to a testing environment specified by the environment variable"
            }
        }
        stage("Approval"){
            steps{
                echo "Approval started and completed!"
                sleep 10
            }
        }
        stage("Deploy to Production"){
            steps{
                echo "${TESTING_ENVIRONMENT}, Deploy to Production started and completed!"
                
            }
        }

    }
}


